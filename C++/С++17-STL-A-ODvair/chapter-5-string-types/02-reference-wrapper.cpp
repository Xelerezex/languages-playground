#include "tools.h"

namespace std
{
    template<typename T>
    class my_reference_wrapper
    {
        private:
            T *m_ptr;
        public:
            my_reference_wrapper(T& t) noexcept : m_ptr(&t) {}

            operator T& () const noexcept { return *m_ptr; }
            T& get() const noexcept { return *m_ptr; }
    };

    template<typename T>
    my_reference_wrapper<T> my_ref(T& t);
}

int main()
{
    int result = 0;
    auto task = [](int& r)
    {
        r = 42;
    };

    std::thread t(task, std::my_ref(result));
}
