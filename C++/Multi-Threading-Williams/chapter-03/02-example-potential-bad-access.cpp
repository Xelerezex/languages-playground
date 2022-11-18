#include <mutex>

class some_data
{
    int a;
    std::string b;
public:
    void do_something()
    {
    }
};

class data_wrapper
{
private:
    some_data m_data;
    std::mutex m_mutex;

public:
    template<typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        func(m_data);
    }
};

some_data* unprotected;

void malicious_function(some_data& protected_data)
{
    unprotected = &protected_data;
}

data_wrapper x;

void foo()
{
    x.process_data(malicious_function);
    unprotected->do_something();
}

int main()
{
    foo();
}
