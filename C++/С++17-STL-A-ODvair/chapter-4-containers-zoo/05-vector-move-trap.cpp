#include "tools.h"

struct Bad
{
    int x = 0;
    Bad() = default;
    Bad(const Bad&) { puts("copy Bad"); }
    Bad(Bad&&) { puts("move Bad"); }
};

struct Good
{
    int x = 0;
    Good() = default;
    Good(const Good&) { puts("copy Good"); }
    Good(Good&&) noexcept { puts("move Good"); }
};

class ImplicitlyGood
{
    std::string x;
    Good y;
};

class ImplicitlyBad
{
    std::string x;
    Bad y;
};

template<class T>
void test_resizing()
{
    std::vector<T> vec(1);
    vec.resize(vec.capacity() + 1);
}

int main()
{
    test_resizing<Good>();
    test_resizing<Bad>();
    test_resizing<ImplicitlyGood>();
    test_resizing<ImplicitlyBad>();
}
