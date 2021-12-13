#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

recursive_mutex rm;
mutex mtx;

void Foo(int a)
{
    rm.lock();
    cout << a << endl;

    this_thread::sleep_for(chrono::milliseconds(300));

    if (a <= 1)
    {
        cout << endl;
        rm.unlock();
        return;
    }

    a--;
    Foo(a);
    rm.unlock();
}


int main()
{
    thread t1(Foo, 10);
    thread t2(Foo, 10);

    t1.join();
    t2.join();
}
