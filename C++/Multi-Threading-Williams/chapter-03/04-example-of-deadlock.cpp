#include <mutex>
#include <thread>
#include <iostream>

#define SLEEP(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

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

    // https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom#3279550
    // https://stackoverflow.com/questions/5695548/public-friend-swap-member-function
    friend void swap (X& lhs, X& rhs);
};

void swap (X& lhs, X& rhs)
{
    if (&lhs == &rhs)
    {
        return;
    }

    std::lock(lhs.m, rhs.m);

    std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
    SLEEP(10)
    std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
    SLEEP(10)

    swap(lhs.some_detail, rhs.some_detail);
}
/***************************************************************************/

int main()
{
    X lhs(some_big_object{17});
    X rhs(some_big_object{38});

    // Cause ADL couldn't find friend function
    void swap (X& lhs, X& rhs);

    // If swap called from two threads, and arguments in function changes there
    // position - without std::adopt_lock wil be deadlock
    std::thread second_thread(swap, std::ref(rhs), std::ref(lhs));
    std::thread third_thread(swap, std::ref(lhs), std::ref(rhs));

    second_thread.join();
    third_thread.join();

    std::cout << "If you read this there is no deadlock" << std::endl;
}
