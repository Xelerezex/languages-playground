#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx1;
mutex mtx2;

void Print1()
{
    mtx1.lock(); // 1!!!!!1

    this_thread::sleep_for(chrono::milliseconds(10));

    mtx2.lock();

    for (int i = 0; i < 5; ++i)
    {
        for (int i = 0; i < 5; ++i)
        {
            cout << '*';
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;

    mtx1.unlock();

    mtx2.unlock();
}

void Print2()
{
    mtx1.lock();  // 1!!!!!1

    this_thread::sleep_for(chrono::milliseconds(10));

    mtx2.lock();

    for (int i = 0; i < 5; ++i)
    {
        for (int i = 0; i < 5; ++i)
        {
            cout << '#';
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;

    mtx1.unlock();

    mtx2.unlock();
}

int main()
{
    thread t1(Print1);
    thread t2(Print2);

    t1.join();
    t2.join();
}
