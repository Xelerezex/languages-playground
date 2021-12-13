#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(3'000));

    cout << "ID = " << this_thread::get_id() << '\n'
         <<"==========    DoWork STARTED    ========" << endl;

    this_thread::sleep_for(chrono::milliseconds(5'000));

    a *= 2;

    cout << "ID = " << this_thread::get_id() << '\n'
         << "==========    DoWork STOPED    ========" << endl;
}

int main()
{
    int q = 5;

    thread t(DoWork, std::ref(q));



    for (size_t t = 0; t < 20; ++t)
    {
        cout << "ID = " << this_thread::get_id() << ";\n"
             << " Iteration = " << t << "\tmain" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t.join();
    cout << "Value of \'q\' = " << q << endl;
}
