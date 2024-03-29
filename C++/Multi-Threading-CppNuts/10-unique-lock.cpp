// TOPIC: unique_lock In C++
//
// NOTES:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//     a. Can Have Different Locking Strategies
//     b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//     c. recursive locking
//     d. transfer of lock ownership (move not copy)
//     e. condition variables. (See this in coming videos)
//
// Locking Strategies
//    TYPE           EFFECTS(S)
// 1. defer_lock  do not acquire ownership of the mutex.
// 2. try_to_lock  try to acquire ownership of the mutex without blocking.
// 3. adopt_lock  assume the calling thread already has ownership of the mutex.

#include <iostream>
#include <thread>
#include <mutex>

#define EXAMPLE_1

std::mutex m1;
int buffer = 0;

#if defined(EXAMPLE_0)

void task (std::string threadNumber, int loopFor)
{
   std::unique_lock<std::mutex> lock(m1);
   for (int i = 0; i < loopFor; ++i)
   {
      buffer++;
      std::cout << threadNumber << buffer << std::endl;
   }
}

#elif defined(EXAMPLE_1)

void task (std::string threadNumber, int loopFor)
{
   std::unique_lock<std::mutex> lock(m1, std::defer_lock);
   lock.lock();
   for (int i = 0; i < loopFor; ++i)
   {
      buffer++;
      std::cout << threadNumber << buffer << std::endl;
   }
}

#endif

int main()
{
    std::thread t1(task, "T1 ", 10);
    std::thread t2(task, "T2 ", 10);

    t1.join();
    t2.join();
    return 0;
}
