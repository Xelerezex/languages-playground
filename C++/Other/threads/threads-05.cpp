#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Test
{
    public:
        void DoWork_0()
        {
            this_thread::sleep_for(chrono::milliseconds(3'000));

            cout << "ID = " << this_thread::get_id() << '\n'
                 <<"==========    DoWork_0 STARTED    ========" << endl;

            this_thread::sleep_for(chrono::milliseconds(5'000));

            cout << "ID = " << this_thread::get_id() << '\n'
                 << "==========    DoWork_0 STOPED    ========" << endl;
        }

        void DoWork_1(int a)
        {
            this_thread::sleep_for(chrono::milliseconds(3'000));

            cout << "ID = " << this_thread::get_id() << '\n'
                 <<"==========    DoWork_1 STARTED    ========" << endl;

            this_thread::sleep_for(chrono::milliseconds(5'000));

            cout << "param = " << a << endl;

            cout << "ID = " << this_thread::get_id() << '\n'
                 << "==========    DoWork_1 STOPED    ========" << endl;
        }

        int Sum(int a, int b)
        {
            this_thread::sleep_for(chrono::milliseconds(3'000));

            cout << "ID = " << this_thread::get_id() << '\n'
                 <<"==========    Sum STARTED    ========" << endl;

            this_thread::sleep_for(chrono::milliseconds(5'000));

            cout << "ID = " << this_thread::get_id() << '\n'
                 << "==========    Sum STOPED    ========" << endl;

            return a + b;
        }
};

int main()
{
    Test tst;
    int result = 0;

    thread t(
        [&result, &tst] () {
            result = tst.Sum(69, 42);
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
