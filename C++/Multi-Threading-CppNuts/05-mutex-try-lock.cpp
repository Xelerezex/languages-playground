// TOPIC: std::mutex::try_lock() On Mutex In C++11 Threading
// 
// 0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns 
//    false.
// 1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
// 2. If try_lock is called again by the same thread which owns the mutex, the behavior is undefined.
//    It is a dead lock situation with undefined behavior. (if you want to be able to lock the same mutex by same 
//    thread more than one time the go for recursive_mutex)

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

        for (int i = 0; i < 100'000; ++i)
        {
            if (mtx.try_lock())
            {
                ++counter;
                mtx.unlock();
            }
        }
    }

    int get() const
    {
        return counter;
    }

private:
    int counter = 0;
    std::mutex mtx;
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
