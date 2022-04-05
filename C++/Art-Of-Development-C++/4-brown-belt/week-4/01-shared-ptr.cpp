#include "tools.h"

struct Actor
{
    Actor() { std::cout << "I was born! :)" << std::endl; }
    ~Actor() { std::cout << "I died! :(" << std::endl; }
    void DoWork() { std::cout << "I did some job" << std::endl; }
};

void run(Actor* ptr)
{
    if (ptr)
    {
        ptr->DoWork();
    }
    else
    {
        std::cout << "An actor was expected;" << std::endl;
    }
}

int main()
{
    std::shared_ptr<Actor> ptr = std::make_shared<Actor>();
    run(ptr.get());
    auto ptr2 = ptr;

    run(ptr2.get());
    run(ptr.get());
}
