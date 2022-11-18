#include <mutex>
#include <thread>
#include <iostream>

/***************************************************************************/
class some_big_object
{
    int inner = 0;
public:
    some_big_object(int outer) : inner{outer} {}

    friend void swap (some_big_object& lhs, some_big_object& rhs);
};

void swap (some_big_object& lhs, some_big_object& rhs)
{
    using std::swap;
    swap(lhs.inner, rhs.inner);
}
/***************************************************************************/

/***************************************************************************/
class X
{
private:
    some_big_object some_detail;
    mutable std::mutex m;

public:
    X(some_big_object const& sd)
        : some_detail(sd)
    {}

    friend void swap (X& lhs, X& rhs);
};

void swap (X& lhs, X& rhs)
{
    if (&lhs == &rhs)
    {
        return;
    }


    std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
    std::lock(lock_a, lock_b);

    swap(lhs.some_detail, rhs.some_detail);
}
/***************************************************************************/

int main()
{
    X lhs(some_big_object{17});
    X rhs(some_big_object{38});

    void swap (X& lhs, X& rhs);

    std::thread second_thread(swap, std::ref(rhs), std::ref(lhs));
    std::thread third_thread(swap, std::ref(lhs), std::ref(rhs));

    second_thread.join();
    third_thread.join();

    std::cout << "If you read this there is no deadlock" << std::endl;
}
