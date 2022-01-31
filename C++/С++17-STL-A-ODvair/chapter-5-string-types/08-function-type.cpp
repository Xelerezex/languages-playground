#include "tools.h"

int my_abs(int x)
{
    return x < 0 ? -x : x;
}

long unusual(long x, int y = 3)
{
    return x + y;
}

int main()
{
    {
        std::function<int(int)> f;
        ASSERT(!f);

        f = my_abs;

        ASSERT_EQUAL(f(-42), 42);
        f = [] (long x) { return unusual(x); };
        ASSERT_EQUAL(f(-42), -39);
    }
    {
        std::function<int(int)> f;

        f = [i = 0] (int) mutable { return ++i; };
        ASSERT_EQUAL(f(-42), 1);
        ASSERT_EQUAL(f(-42), 2);

        auto g = f;
        ASSERT_EQUAL(f(-42), 3);
        ASSERT_EQUAL(f(-42), 4);
        ASSERT_EQUAL(g(-42), 3);
        ASSERT_EQUAL(g(-42), 4);
    }
}
