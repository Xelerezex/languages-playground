#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

#define VAR_4

#ifdef VAR_0

void fun(int x)
{
    while (x --> 0)
    {
        std::cout << x << std::endl;
    }
}

#elif defined(VAR_1)

#elif defined(VAR_2)

class Base
{
public:
    void operator() (int x)
    {
        while (x --> 0)
        {
            std::cout << x << std::endl;
        }
    }
};

#elif defined(VAR_3)

class Base
{
public:
    void run (int x)
    {
        while (x --> 0)
        {
            std::cout << x << std::endl;
        }
    }
};

#elif defined(VAR_4)

class Base
{
public:
    static void run (int x)
    {
        while (x --> 0)
        {
            std::cout << x << std::endl;
        }
    }
};

#endif

int main()
{

    auto startTime = std::chrono::high_resolution_clock::now();

#ifdef VAR_0 /* 1. Function Pointer -- this is the very basic form of creating threads. */

    std::thread t(fun, 10);
    t.join();

#elif defined(VAR_1) /* 2. Lambda Function */

    auto fun = [] (int x) {
        while (x --> 0)
        {
            std::cout << x << std::endl;
        }
    };

    std::thread t(fun, 10);
    t.join();

#elif defined(VAR_2) /* 3. Functor (Function Object) */

    std::thread t(Base{}, 13);

    // Base{}(15);

    t.join();

#elif defined(VAR_3) /* 4. Non-static member function */

    Base b;
    std::thread t(&Base::run, &b, 13);

    t.join();


#elif defined(VAR_4) /* 5. Static member function */

    std::thread t(&Base::run, 13);

    t.join();

#endif


    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);
    std::cout << "Finished in: "  << duration.count() << "ms" << std::endl;

    return 0;
}
