// Rule #32
// Use open inheritance to model the "Is" relationship

#include "tools.h"

class Person { };
class Student : public Person { };

void eat(const Person& p) {}
void study(const Student& s) {}

class Rectangle
{
    public:
        virtual void setHeight(int newHeight) {}
        virtual void setWidth(int newWidth)   {}

        virtual int height() const {}
        virtual int width() const {}
};

void makeBigger(Rectangle& r)
{
    int oldHeight = r.height();

    r.setWidth(r.width() + 10);

    assert(r.height() == oldHeight);
}

class Square : public Rectangle { };


int main()
{
    {
        Person p;
        Student s;

        eat(p);
        eat(s);

        study(s);
        // study(p);
    }
    {
        Square s;

        assert(s.width() == s.height());

        makeBigger(s);

        assert(s.width() == s.height());
    }
}
