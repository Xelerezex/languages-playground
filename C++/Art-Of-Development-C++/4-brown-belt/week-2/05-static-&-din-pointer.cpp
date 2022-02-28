#include <iostream>

struct Parent
{
    virtual std::string Name() const { return "Parent"; }
};

struct Child : Parent
{
    virtual std::string Name() const override { return "Child"; }
};

void Print(const Parent& object)
{
    std::cout << object.Name() << std::endl;
}

int main()
{
    // Статический тип ссылки — это тип, известный на этапе компиляции. В нашем примере
    // статический тип параметра object — это const Parent&.
    Print(Parent());

    // Динамический тип ссылки — это тип объекта, на который она ссылается в данный момент времени.
    // Динамическим типом параметра object во время первого вызова функции Print будет const Parent,
    // во время второго вызова функции Print — const Child.
    Print(Child());
}
