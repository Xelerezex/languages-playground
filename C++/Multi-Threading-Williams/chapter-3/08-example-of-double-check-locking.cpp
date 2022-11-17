#include <memory>
#include <mutex>

class some_resource
{
public:
    void do_something() {}
};

std::shared_ptr<some_resource> resource_ptr;
std::mutex resource_mutex;

// Here is redundant serialization
void foo()
{
    std::unique_lock<std::mutex> lock(resource_mutex);

    if (!resource_ptr)
    {
        resource_ptr.reset(new some_resource);
    }
    lock.unlock();
    resource_ptr->do_something();
}

int main()
{
    foo();
}
