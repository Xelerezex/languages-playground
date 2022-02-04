#include "tools.h"

template<typename T>
class my_unique_ptr
{
    private:
        T *m_ptr = nullptr;
    public:
        constexpr my_unique_ptr() noexcept = default;

        constexpr my_unique_ptr(T *p) noexcept
            : m_ptr(p)
        {}

        T *get() const noexcept
        {
            return m_ptr;
        }

        operator bool() const noexcept
        {
            return boll(get());
        }

        T &operator*() const noexcept
        {
            return *get();
        }

        T *operator->() const noexcept
        {
            return get();
        }

        void reset(T *p = nullptr) noexcept
        {
            T *old_p = std::exchange(m_ptr, p);
            delete old_p;
        }

        T *release() noexcept
        {
            return std::exchange(m_ptr, nullptr);
        }

        my_unique_ptr(my_unique_ptr&& rhs) noexcept
        {
            this->reset(rhs.release());
        }

        my_unique_ptr& operator=(my_unique_ptr&& rhs)
        {
            reset(rhs.release());
            return *this;
        }

        ~my_unique_ptr()
        {
            reset();
        }
};

template<typename T, typename... Args>
my_unique_ptr<T> my_make_unique(Args&&... args)
{
    return my_unique_ptr<T>(new T(std::forward<Args>(args)...));
}

struct Widget
{
    virtual ~Widget();
};

struct WidgetImpl : Widget
{
    WidgetImpl(int size)
    {}
};

struct WidgetHolder
{
    void take_ownership_of(Widget *) noexcept
    {}
};

void use(WidgetHolder&)
{}

int main()
{
    auto w = my_make_unique<WidgetImpl>(30);
    auto wh = my_make_unique<WidgetHolder>();
    wh->take_ownership_of(w.release());
    use(*wh);
}
