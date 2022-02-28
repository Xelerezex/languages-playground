#include <iostream>

struct Parent;
struct Child;

void PrintType(Parent*) { std::cout << "Parent" << std::endl; }
void PrintType(Child*)  { std::cout << "Child"  << std::endl; }

struct Parent
{
    virtual void Print() { PrintType(this); }
};


struct Child : Parent
{
    void Print() override { PrintType(this); }
};

int main()
{
    // Итак, главный вывод — this всегда имеет тип указателя
    // на тот класс, в методе которого он используется.
    Child().Print();
}
