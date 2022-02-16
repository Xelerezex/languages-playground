#include "tools.h"

template<class T>
class simple_packaged_task
{
    private:
        std::function<T()> m_func;
        std::promise<T>    m_promise;
    public:

        template<class F>
        simple_packaged_task(const F& f) : m_func(f) {}

        auto get_future() { return m_promise.get_future(); }

        void operator()()
        {
            try
            {
                T result = m_func();
                m_promise.set_value(result);
            }
            catch(...)
            {
                m_promise.set_exception(std::current_exception());
            }
        }
};

int main()
{

}
