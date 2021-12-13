#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(3'000));

    cout << "==========    DoWork STARTED    ========" << endl;
    this_thread::sleep_for(chrono::milliseconds(5'000));

    cout << "a + b = " << a + b << endl;
    this_thread::sleep_for(chrono::milliseconds(3'000));

    cout << "==========    DoWork STOPED    ========" << endl;
}

int main()
{
    thread th(DoWork, 2, 3);

    for (size_t t = 0; true; ++t)
    {
        cout << "ID = " << this_thread::get_id()<< " Iteration = " << t << "\tmain" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();
}
