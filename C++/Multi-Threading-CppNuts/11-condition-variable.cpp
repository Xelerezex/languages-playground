// TOPIC: Condition Variable In C++ Threading
//
// IMPORTANT POINT: CV are used for two purpose
// A. Notify other threads
// B. Waiting for some conditions

// NOTES:
// 1. Condition Variables allows running threads to wait some conditions and once those conditions are met the waiting,
//    is notified using:
//      a. notify_one();
//      b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition
// 6. If some thread want to wait on some condition than it has to do this things:
//     a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);
//     b. Execute wait(), wait_for() or wait_until(). The wait operations atomically release the mutex
//        and suspend the execution of the thread.
//     c. When the condition variable is notified, the thread is awakened, and the mutex is atomically reacquired.
//        The thread should then check the condition and resume waiting if the wake up was spurious.


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex mtx;
long balance = 0;

void addMoney (int money)
{
    std::lock_guard<mutex> lg(mtx);
    balance += money;
    cout << "Amount Added Current Balance: " << balance << endl;
    cv.notify_one();
}

void withdrowMoney (int money)
{
    std::unique_lock<mutex> ul(mtx);
    cv.wait(ul, [] {return (balance != 0) ? true : false; });

    if (balance >= money)
    {
        balance -= money;
        cout << "Amount Deduced: " << money << endl;
    }
    else
    {
        cout << "Amount Can't Be Deducted, Current Balance Is Less Than " << money << endl;
    }
    cout << "Current Balanse is: " << balance << endl;
}

int main ()
{
    std::thread t1(withdrowMoney, 500);
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();
}
