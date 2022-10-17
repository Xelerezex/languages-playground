#include <iostream>
#include <thread>
#include <vector>
#include <string>

void some_function()
{
    for (const auto& item : {"one", "two", "three"})
    {
        std::cerr << item << std::endl;
    }
}

void some_other_function(int number)
{
    for (const auto& item : {"four", "six", "seven"})
    {
        std::cerr << item << " " << number << std::endl;
    }
}

std::thread f()
{
    void some_function();
    return std::thread(some_function);
}

std::thread g()
{
    void some_other_function(int number);
    std::thread t(some_other_function, 42);
    return t;
}

int main()
{
    std::thread t1=f();
    t1.join();
    std::thread t2=g();
    t2.join();
}
