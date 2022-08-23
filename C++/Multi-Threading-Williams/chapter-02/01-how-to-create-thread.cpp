#include <iostream>
#include <thread>

void do_job()
{
    std::cerr << "Job done." << std::endl;
}

void do_another_job()
{
    std::cerr << "This Job done too." << std::endl;
}

class Class
{
public:
    // Callback operator
    void operator()() const
    {
        do_job();
        do_another_job();
    }
};


int main()
{
    Class object;

    // copy
    std::thread t1(object);
    t1.join();

    // only if Class has functor
    std::thread t2{Class()};
    t2.join();

    // with lambda
    std::thread t3([&] () {
        do_job();
        do_another_job();
    });
    t3.join();

    return 0;
}
