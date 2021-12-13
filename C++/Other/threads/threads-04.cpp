#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(3'000));

    cout << "ID = " << this_thread::get_id() << '\n'
         <<"==========    DoWork STARTED    ========" << endl;

    this_thread::sleep_for(chrono::milliseconds(5'000));

    cout << "ID = " << this_thread::get_id() << '\n'
         << "==========    DoWork STOPED    ========" << endl;
    return a + b;
}

int main()
{
    int result;
    thread t(
        [&result] () {
            result = Sum(42, 69);
        }
    );

    for (size_t t = 0; t < 20; ++t)
    {
        cout << "ID = " << this_thread::get_id() << ";\n"
             << " Iteration = " << t << "\tmain" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t.join();
    cout << "Sum result = " << result << endl;
}
