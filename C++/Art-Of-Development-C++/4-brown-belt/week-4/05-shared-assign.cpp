#include "tools.h"

struct Actor
{
    Actor(std::string name) : name_(move(name)) { std::cout << name_ << " was born! :)" << std::endl; }
    ~Actor() { std::cout  << name_ <<  " died! :(" << std::endl; }
    void DoWork() { std::cout  << name_ <<  " did some job" << std::endl; }

    std::string name_;
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
    auto ptr1 = std::make_unique<Actor>("Alice");
    auto ptr2 = std::make_unique<Actor>("Boris");

    ptr1 = move(ptr2);

    run(ptr1.get());
    run(ptr2.get());
}
