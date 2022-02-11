#include "tools.h"


// Mutex in function
void log(const char *message)
{
    // Static is really important!
    static std::mutex m;
    m.lock();
    puts(message);
    m.unlock();
}

// or global mutex example:
static std::mutex m;

void log1(const char *message)
{
    m.lock();
    printf("LOG1: %s\n", message);
    m.unlock();
}

void log2(const char *message)
{
    m.lock();
    printf("LOG2: %s\n", message);
    m.unlock();
}

// Best way is class:
struct Logger
{
    std::mutex m_mtx;

    void log1(const char *message)
    {
        m.lock();
        printf("LOG1: %s\n", message);
        m.unlock();
    }

    void log2(const char *message)
    {
        m.lock();
        printf("LOG2: %s\n", message);
        m.unlock();
    }
};

int main()
{

}
