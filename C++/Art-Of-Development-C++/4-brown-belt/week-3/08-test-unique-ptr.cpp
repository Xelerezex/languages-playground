#include <iostream>
#include <memory>

using namespace std;

struct Actor
{
    Actor() { cout << "I was born!" << endl; }
    ~Actor() { cout << "I died!" << endl; }
    void DoWork() { cout << "I did some job!" << endl; }
};

void run(Actor* ptr)
{
    if (ptr)
    {
        ptr->DoWork();
    }
    else
    {
        cout << "An actor was expected" << endl;
    }
}

int main()
{
    auto ptr = unique_ptr<Actor>(new Actor);
    run(ptr.get());
    auto ptr2 = move(ptr);
    run(ptr2.get());
    run(ptr.get());

    return 0;
}
