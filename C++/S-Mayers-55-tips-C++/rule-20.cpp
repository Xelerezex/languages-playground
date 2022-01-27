// Rule #20
// Prefer passing by reference to const to passing by value
#include "tools.h"

class Person
{
    public:
        Person() {}
        virtual ~Person() {}

    private:
        std::string name;
        std::string address;
};

class Student : public Person
{
    public:
        Student() {}
        ~Student() {}
    private:
        std::string schoolName;
        std::string schollAddress;
};

// bool validateStudent(Student s)        <- Wrong!
bool validateStudent(const Student& s) // <- Right!
{
    return true;
}

int main()
{
    {
        Student plato;

        bool platoIsOk = validateStudent(plato);
    }
}
