#include <thread>
#include <utility>

// This example is upgrade of class thread_guard
// in 04-create-thread-guard.cpp

/*********************************************************************************************/
// Previously declarated in listing 2.1
void do_something(int& i)
{
    ++i;
}

void do_something_in_current_thread()
{}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j = 0; j < 1000000; ++j)
        {
            do_something(i);
        }
    }
};
/*********************************************************************************************/

class scoped_thread
{
private:
    std::thread m_thread;

public:
    explicit scoped_thread (std::thread t_)
        : m_thread(std::move(t_))
    {
        if (!m_thread.joinable())
        {
            throw std::logic_error("No thread");
        }
    }

    ~scoped_thread()
    {
        m_thread.join();
    }

    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};

void f()
{
    int some_local_state;
    scoped_thread second_thread(std::thread(func(some_local_state)));

    do_something_in_current_thread();
}

int main()
{
    f();
}
