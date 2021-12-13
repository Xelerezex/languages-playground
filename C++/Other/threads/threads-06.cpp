#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void Print(char ch)
{
    mtx.lock();
    for (int i = 0; i < 5; ++i)
    {
        for (int i = 0; i < 5; ++i)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;

    mtx.unlock();
}

int main()
{
    thread t1(Print, '*');
    thread t2(Print, '#');

    t1.join();
    t2.join();
}
