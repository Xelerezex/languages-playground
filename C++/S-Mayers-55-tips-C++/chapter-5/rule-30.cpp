// Rule #30
// Think twice about built-in functions.

#include "tools.h"

class Person
{
    public:
        int age() const { return theAge; }

    private:
        int theAge;
};

class Base
{
    public:
        Base();
    private:
        std::string bm1, bm2;
};

class Derived : public Base
{
    public:

        Derived();

    private:
        std::string dm1, dm2, dm3;
};

Derived::Derived()
{
    Base::Base();

    try { dm1.std::string::string(); }
    catch (...)
    {
        Base::~Base();
        throw;
    }

    try { dm2.std::string::string(); }
    catch (...)
    {
        dm1.std::string::~string();
        Base::~Base();
        throw;
    }

    try { dm3.std::string::string(); }
    catch (...)
    {
        dm2.std::string::string();
        dm1.std::string::~string();
        Base::~Base();
        throw;
    }
}

int main()
{

}
