// TOPIC: std::try_lock() On Mutex In C++11 Threading
//
// 0. std::try_lock() tries to lock all the mutexes passed in it one by one in given order.
// 1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
// 2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
// 3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int X = 0, Y = 0;
std::mutex m1, m2;

void doSomeWorkForSeconds (int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementXY(int& XorY, std::mutex& m, const std::string desc)
{
    for (int i = 0; i < 5; ++i)
    {
        m.lock();
        ++XorY;
        std::cout << desc << XorY << '\n';
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY ()
{
    int useCount = 5;
    int XplusY = 0;
    while (1)
    {
        int lockResult = std::try_lock(m1, m2);
        if (lockResult == -1)
        {
            if (X != 0 && Y != 0)
            {
                --useCount;
                XplusY += X + Y;
                X = 0;
                Y = 0;
                std::cout << "X + Y" << XplusY << '\n';
            }
            m1.unlock();
            m2.unlock();
            if (useCount == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");
    std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);
    std::cout << "Finished in: "  << duration.count() << "ms" << std::endl;

    return 0;
}
