#include "tools.h"

void prep_work()
{
}

void main_work()
{
}

int main()
{
    using std::chrono_literals::operator""ms;
    auto count_ms = [] (auto&& d) -> int {
        using namespace std::chrono;
        return duration_cast<milliseconds>(d).count();
    };

    {
        std::promise<int> p1, p2;
        std::future<int> f1 = p1.get_future();
        std::future<int> f2 = p2.get_future();

        p1.set_value(42);
        assert(f1.get() == 42);

        std::thread t(
            [&] () {
                std::this_thread::sleep_for(100ms);
                p2.set_value(43);
            }
        );

        auto start_time = std::chrono::system_clock::now();
        assert(f2.get() == 43);
        auto elapsed = std::chrono::system_clock::now() - start_time;
        printf("f2.get() took %dms.\n", count_ms(elapsed));
        t.join();
    }
    {
        std::promise<void> ready_p;
        std::future<void>  ready_f = ready_p.get_future();


        std::thread thread_b(
            [&] () {
                prep_work();
                ready_p.set_value();
                main_work();
            }
        );

        ready_f.wait();
    }
}
