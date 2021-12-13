#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>


using namespace std;
using namespace chrono_literals;


shared_mutex shared_mut;


using shrd_lck = shared_lock<shared_mutex>;
using uniq_lck = unique_lock<shared_mutex>;


static void print_exclusive()
{
    uniq_lck l {shared_mut, defer_lock};

    if (l.try_lock())
    {
        cout << "Got exclusive lock." << endl;
    }
    else
    {
        cout << "Unable to lock exclusively." << endl;
    }
}


static void exclusive_throw()
{
    uniq_lck l {shared_mut};
    throw 123;
}


int main()
{
    {
        shrd_lck sl1 {shared_mut};
        cout << "Shared lock once." << endl;

        {
            shrd_lck sl2 {shared_mut};
            cout << "Shared lock twice." << endl;
            print_exclusive();
        }

        cout << "Shared lock once again." << endl;
        print_exclusive();
    }

    cout << "lock is free." << endl;

    try
    {
        exclusive_throw();
    }
    catch (int e)
    {
        cout << "Got exception " << e << '\n';
    }
    print_exclusive();
}
