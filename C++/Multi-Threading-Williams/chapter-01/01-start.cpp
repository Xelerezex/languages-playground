#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Henlo wrld\n";
}

int main()
{
    std::thread t(hello);
    t.join();               // Waits until thread ends

    return 0;
}
