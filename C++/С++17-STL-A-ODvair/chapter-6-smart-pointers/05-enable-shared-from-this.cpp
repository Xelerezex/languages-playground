#include "tools.h"

template<class T>
class my_enable_shared_from_this
{
    private:
        std::weak_ptr<T> m_weak;
    public:
        my_enable_shared_from_this(const my_enable_shared_from_this&) {}
        my_enable_shared_from_this& operator=(const my_enable_shared_from_this&) {}
        std::shared_ptr<T> shared_from_this() const
        {
            return std::shared_ptr<T>(m_weak);
        }
};

struct Widget : std::enable_shared_from_this<Widget>
{
    template<class F>
    void call_on_me(const F& f)
    {
        f(this->shared_from_this());
    }
};

int main()
{
    {
        auto sa = std::make_shared<Widget>();

        assert(sa.use_count() == 1);
        sa->call_on_me(
            [] (auto sb) {
                assert(sb.use_count() == 2);
            }
        );

        Widget w;
        try
        {
            w.call_on_me(
                [] (auto) {}
            );
        }
        catch (const std::bad_weak_ptr&)
        {
            puts("Caught!");
        }
    }
}
