#include <iostream>
#include <thread>

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

int main()
{
    int some_local_state = 0;
    func my_func(some_local_state);

    std::thread t1(my_func);
    t1.detach(); // leak coud be fixed with t1.join();

    return 0;
}

// SUMMARY: If .detach() - no reference & no pointers
