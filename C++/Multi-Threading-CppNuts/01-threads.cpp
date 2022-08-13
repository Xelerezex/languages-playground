#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
using ull = unsigned long long int;

ull EvenSum = 0;
ull OddSum = 0;

void findEven(ull start, ull end)
{

    for (ull index = start; index <= end; ++index)
    {
        if ((index & 1) == 0)
        {
            EvenSum += index;
        }
    }
}

void findOdd(ull start, ull end)
{

    for (ull index = start; index <= end; ++index)
    {
        if ((index & 1) == 1)
        {
            OddSum += index;
        }
    }
}

int main()
{
    ull start = 0, end = 1'900'000'000;

    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    // findOdd(start, end);
    // findEven(start, end);

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);

    std::cout << "EvenSum: " << EvenSum << std::endl;
    std::cout << "OddSum: "  << OddSum  << std::endl;

    std::cout << "Finished in: "  << duration.count() << "ms" << std::endl;

    return 0;
}
