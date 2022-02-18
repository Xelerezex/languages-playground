#include "tools.h"

std::string to_string(std::thread::id id)
{
    std::ostringstream o;
    o << id;
    return o.str();
}

int main()
{
    std::mutex ready;
    std::unique_lock lk(ready);
    std::vector<std::thread> threads;

    auto task = [&] () {
        (void)std::lock_guard(ready);

        auto my_id = std::this_thread::get_id();
        auto iter = std::find_if(
            threads.begin(), threads.end(),
            [=] (const std::thread& t) {
                return t.get_id() == my_id;
            }
        );

        printf("Thread %s %s in the list.\n", to_string(my_id).c_str(), iter != threads.end() ? "is" : "is not");
    };

    std::vector<std::thread> others;
    for (int i = 0; i < 10; ++i)
    {
        std::thread t(task);
        if (i % 2)
        {
            threads.push_back(std::move(t));
        }
        else
        {
            others.push_back(std::move(t));
        }
    }

    ready.unlock();

    for (std::thread& t : threads) t.join();
    for (std::thread& t : others) t.join();
}
