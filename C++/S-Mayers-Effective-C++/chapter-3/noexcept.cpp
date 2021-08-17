#include <iostream>

using namespace std;


void Foo() noexcept
{
    try
    {
        throw std::runtime_error("error");
    }
    catch(...)
    {
        cout << "true" << endl;
        //::std::terminate();
    }
}

void Bar() noexcept
{

        throw std::runtime_error("error");

}


int main () {


    Foo();


    return 0;
}
