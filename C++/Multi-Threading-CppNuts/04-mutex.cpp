// TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section
//
// Mutex: Mutual Exclusion
//
// RACE CONDITION:
// 0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.
//
// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock() , unlock() on mutex to avoid race condition.

// TOPIC: Use Of join(), detach() and joinable() In Thread In C++ (C++11)
//
// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)
//
//
// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
//    double detach() will result into program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.
//
// NOTES:
// Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

#include <bitset>
#include <iomanip>

#define VER_1

class App
{
public:
    void run ()
    {
        mu.lock();
        ++myAmount;
        mu.unlock();
    }

    int get() const
    {
        return myAmount;
    }

private:
    int myAmount = 0;
    std::mutex mu;
};

int main()
{

    auto startTime = std::chrono::high_resolution_clock::now();

    App app;
    std::thread t1(&App::run, &app);
    std::thread t2(&App::run, &app);
    t1.join();
    t2.join();

    std::cout << app.get() << std::endl;

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);
    std::cout << "Finished in: "  << duration.count() << "ms" << std::endl;

    return 0;
}
