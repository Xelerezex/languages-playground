#include "tools.h"

int main()
{
    using namespace std::literals;

    std::thread a (
        [] () {
            puts("Thread A says hello ~0ms");
            std::this_thread::sleep_for(10ms);
            puts("Thread A says goodbye ~10ms");
        }
    );

    std::thread b (
        [] () {
            puts("Thread B says hello ~0ms");
            std::this_thread::sleep_for(20ms);
            puts("Thread B says goodbye ~20ms");
        }
    );

    puts("The main thread says hello ~0ms");
    a.join();
    b.detach();
    puts("The main thread says goodbye ~10ms");
}
