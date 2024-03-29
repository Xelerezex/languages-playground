#include <iostream>
#include <thread>
#include <vector>
#include <string>

void do_something(int& _i)
{
    ++_i;
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
        std::cout << i << std::endl;
    }
};

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_)
        : t(t_)
    {}

    ~thread_guard()
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
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
    int some_local_state;

    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);

    do_something_in_this_thread();

    return 0;
}

// SUMMARY: Always chech if you .join(), even when exception
