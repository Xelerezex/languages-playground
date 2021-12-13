#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork()
{
    for (size_t t = 0; t < 10; ++t)
    {
        cout << "ID = " << this_thread::get_id() << "Iteration = " << t << "\tDoWork" << endl;
        this_thread::sleep_for(chrono::milliseconds(1'000));
    }
}

int main()
{
    DoWork();

    thread th(DoWork);
    // th.detach();        // Свободное плавание, обрывается при завершении оновного потока

    for (size_t t = 0; t < 10; ++t)
    {
        cout << "ID = " << this_thread::get_id() << " Iteration = " << t << "\tmain" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();            // Дождаться поток
}
