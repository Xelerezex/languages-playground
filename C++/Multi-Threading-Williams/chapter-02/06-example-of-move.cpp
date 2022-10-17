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

void some_other_function()
{
    for (const auto& item : {"four", "six", "seven"})
    {
        std::cerr << item << std::endl;
    }
}

int main()
{
    std::thread t1(some_function);
    std::thread t2 = std::move(t1);
    t1 = std::thread(some_other_function);
    std::thread t3;
    t3 = std::move(t2);
    t1 = std::move(t3); // will terminate
}
