#include <iostream>
#include <thread>
#include <vector>
#include <string>

void do_something(int& _i)
{
    std::cout << _i << std::endl;
}

struct func
{
    int& i;

    func(int& i_) : i(i_) {}

    void operator()()
    {
        for (unsigned j = 0; j < 1'000'000; ++j)
        {
            do_something(i); // potential dangling link
        }
    }
};

void do_something_in_this_thread()
{
    for (const auto& item : {"one", "two", "three"})
    {
        std::cerr << item << std::endl;
    }
}

int main()
{
    int some_local_state = 0;
    func my_func(some_local_state);

    std::thread t1(my_func);

    try
    {
        do_something_in_this_thread();
    }
    catch(...)
    {
        t1.join();
        throw;
    }
    t1.join();

    return 0;
}

// SUMMARY: Always chech if you .join(), even when exception
