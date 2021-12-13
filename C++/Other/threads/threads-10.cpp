#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void Print(char ch)
{
    unique_lock<mutex> unique_guard(mtx, std::defer_lock);

    this_thread::sleep_for(chrono::milliseconds(2000));

    unique_guard.lock();
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
    unique_guard.unlock();

    this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
    thread t1(Print, '*');
    thread t2(Print, '#');
    thread t3(Print, '@');

    t1.join();
    t2.join();
    t3.join();
}
