#include "tools.h"

template<class T>
void my_destroy_at(T *p)
{
    p->~T();
}

template<class FwdIt>
void my_destroy(FwdIt first, FwdIt last)
{
    for (; first != last; ++first)
    {
        my_destroy_at(std::addressof(*first));
    }
}

template<class It, class FwdIt>
FwdIt my_uninitialized_copy(It first, It last, FwdIt out)
{
    using T = typename std::iterator_traits<FwdIt>::value_type;
    FwdIt old_out = out;
    try
    {
        while (first != last)
        {
            ::new (static_cast<void*>(std::addressof(*out))) T(*first);
            ++first;
            ++out;
        }
        return out;
    }
    catch (...)
    {
        std::destroy(old_out, out);
        throw;
    }
}

class T
{
    public:
        ~T() { std::cout << "Dtor" << std::endl; }
};

int main()
{
    {
        T t;
        my_destroy_at(&t);
    }
    {
        alignas(std::string) char b[5 * sizeof (std::string)];
        std::string *sb = reinterpret_cast<std::string *>(b);

        std::vector<const char *> vec = {"quick", "brown", "fox"};

        auto end = my_uninitialized_copy(vec.begin(), vec.end(), sb);

        ASSERT_EQUAL(end, sb + 3);
        my_destroy(sb, end);
    }
}
