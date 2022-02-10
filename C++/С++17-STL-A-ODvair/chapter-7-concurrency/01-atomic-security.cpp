#include "tools.h"

std::atomic<int64_t> x = 0;
std::atomic<bool>    y = false;

void thread_A()
{
    x = 0x42'00000042;
    y = true;
}

void thread_B()
{
    if (x)
    {
        assert(x == 0x42'00000042);
    }
}

void thread_C()
{
    if (y)
    {
        assert(x == 0x42'00000042);
    }
}

int main()
{
    {   // Do not compile
        // std::atomic<int> a, b;
        // a = b;
    }
    {
        std::atomic<int> a, b;
        int shortlived = b;
        a = shortlived;
    }
    {
        std::atomic<int> a, b;
        int shortlived = b.load();
        a.store(shortlived);
    }
    {   // If our processor does not support atomic multiplication instruction
        std::atomic<int> a = 6;
        // a *= 9; no way!

        int expected, desired;
        do
        {
            expected = a.load();
            desired = expected * 9;
        } while (!a.compare_exchange_weak(expected, desired));
    }
}
