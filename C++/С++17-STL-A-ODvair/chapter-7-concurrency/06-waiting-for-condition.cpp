#include "tools.h"

void prep_work()
{
}

void main_work()
{
}

int main()
{
    {   // Not so good realization
        using std::chrono_literals::operator""ms;

        std::atomic<bool> ready = false;

        std::thread thread_b(
            [&] () {
                prep_work();
                ready = true;
                main_work();
            }
        );

        while (!ready)
        {
            std::this_thread::sleep_for(10ms);
        }
    }
    {
        bool ready = false;
        std::mutex ready_mutex;

        std::condition_variable cv;

        std::thread thread_b(
            [&] () {
                prep_work();
                {
                    std::lock_guard lk(ready_mutex);
                    ready = true;
                }
                cv.notify_one();
                main_work();
            }
        );

        {
            std::unique_lock lk(ready_mutex);
            while (!ready)
            {
                cv.wait(lk);
            }
        }
    }
    {   // Best choise
        bool ready = false;
        std::shared_mutex ready_rwlock;

        std::condition_variable_any cv;

        std::thread thread_b(
            [&] () {
                prep_work();
                {
                    std::lock_guard lk(ready_rwlock);
                    ready = true;
                }
                cv.notify_one();
                main_work();
            }
        );

        {
            std::shared_lock lk(ready_rwlock);
            while (!ready)
            {
                cv.wait(lk);
            }
        }
    }
}
