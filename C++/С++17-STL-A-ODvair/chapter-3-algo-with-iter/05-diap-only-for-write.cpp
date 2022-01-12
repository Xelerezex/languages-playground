#include "tools.h"

template<class FwdIt, class T>
void my_fill(FwdIt first, FwdIt last, T value)
{
    while (first != last)
    {
        *first = value;
        ++first;
    }
}

template<class FwdIt, class T>
void my_iota(FwdIt first, FwdIt last, T value)
{
    while (first != last)
    {
        *first = value;
        ++value;
        ++first;
    }
}

template<class FwdIt, class G>
void my_generate(FwdIt first, FwdIt last, G generator)
{
    while (first != last)
    {
        *first = generator();
        ++first;
    }
}

int main()
{
    {
        std::vector<std::string> v(7);
        my_fill(std::begin(v), std::end(v), "std::string");
        std::cerr << v << std::endl;
    }
    {
        std::vector<int> v(7);
        my_iota(std::begin(v), std::end(v), 660);
        std::cerr << v << std::endl;
    }
    {
        std::vector<int> v(7);
        my_generate(std::begin(v), std::end(v), [i = 0] () mutable { return i++ == 6 ? 666 : 0; });
        std::cerr << v << std::endl;
    }
    {
        std::vector<std::string> v(4);

        my_fill(v.begin(), v.end(), "hello");
        ASSERT_EQUAL(v[0], "hello");
        ASSERT_EQUAL(v[1], "hello");
        ASSERT_EQUAL(v[2], "hello");
        ASSERT_EQUAL(v[3], "hello");

        my_iota(v.begin(), v.end(), "hello");
        ASSERT_EQUAL(v[0], "hello");
        ASSERT_EQUAL(v[1], "ello");
        ASSERT_EQUAL(v[2], "llo");
        ASSERT_EQUAL(v[3], "lo");

        my_generate(std::begin(v), std::end(v), [i = 0] () mutable { return ++i % 2 ? "hello" : "world"; });
        ASSERT_EQUAL(v[0], "hello");
        ASSERT_EQUAL(v[1], "world");
        ASSERT_EQUAL(v[2], "hello");
        ASSERT_EQUAL(v[3], "world");
    }
}
