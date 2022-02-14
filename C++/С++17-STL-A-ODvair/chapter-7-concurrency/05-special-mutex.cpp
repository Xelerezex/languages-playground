#include "tools.h"


int main()
{
    using std::chrono_literals::operator""ms;
    {
        std::timed_mutex m;
        std::atomic<bool> ready = false;
        std::thread thread_b(
            [&] () {
                std::lock_guard lk(m);
                puts("Thread B got the lock.");
                ready = true;
                std::this_thread::sleep_for(100ms);
            }
        );

        while(!ready)
        {
            puts("Thread A is waiting for thread B to launch.");
            std::this_thread::sleep_for(10ms);
        }

        puts("Thread A finally got the lock!");
        m.unlock();
    }
    {
        std::timed_mutex m1, m2;
        std::atomic<bool> ready = false;

        auto count_ms = [] (auto&& d) -> int {
            using namespace std::chrono;
            return duration_cast<milliseconds>(d).count();
        };

        std::thread thread_b(
            [&] () {
                std::unique_lock lk1(m1);
                std::unique_lock lk2(m2);
                puts("Thread B got the locks.");
                ready = true;
                std::this_thread::sleep_for(50ms);
                lk1.unlock();
                std::this_thread::sleep_for(50ms);
            }
        );

        while(!ready)
        {
            std::this_thread::sleep_for(10ms);
        }

        auto start_time = std::chrono::system_clock::now();
        auto deadline   = start_time + 100ms;

        bool got_m1 = m1.try_lock_until(deadline);
        auto elapsed_m1 = std::chrono::system_clock::now() - start_time;

        bool got_m2 = m2.try_lock_until(deadline);
        auto elapsed_m2 = std::chrono::system_clock::now() - start_time;

        if (got_m1)
        {
            printf("Thread A got the first lock after %dms.\n", count_ms(elapsed_m1));
            m1.unlock();
        }

        if (got_m2)
        {
            printf("Thread A got the first lock after %dms.\n", count_ms(elapsed_m2));
            m2.unlock();
        }
    }
}
