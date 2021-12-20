// Rule #3
// const - until programm stops to compile

#include <vector>
#include <iostream>

class Widget
{};

class Sum {
    private:
        int a;
    public:
        Sum(int i) : a(i) {}
        Sum A() const { return a; }
};

const Sum operator* (const Sum& lhs, const Sum& rhs)
{
    return lhs.A() * rhs.A();
}

int main()
{
    //-----------------------------------------------------------------------------
    char greeting[] = "Hello!";
    {
        char *p = greeting;                  // non-const pointer, non-const data
    }
    {
        const char *p = greeting;            // non-const pointer, const data
    }
    {
        char * const p = greeting;           // const pointer, non-const data
    }
    {
        const char * const p = greeting;     // non-const pointer, non-const data
    }
    //-----------------------------------------------------------------------------
    {
        auto f1 (
            [] (const Widget *pw) {}         // Here is const Widget, not pointer
        );
    }
    {
        auto f1 (
            [] (Widget const *pw) {}         // Here is the same
        );
    }
    //-----------------------------------------------------------------------------
    {
        std::vector<int> vec;

        const std::vector<int>::iterator iter = vec.begin();

        *iter = 10;     // changes data

        // ++iter;         <- will crash, cause const iter won't change
    }
    {
        std::vector<int> vec;

        std::vector<int>::const_iterator iter = vec.begin();

        // *iter = 10;      <- will crash, cause const_iterator won't change data

        ++iter;         // changes iter
    }
    //-----------------------------------------------------------------------------
    {
        Sum a(10);
        Sum b(69);
        Sum c(1);

        Sum z = a * b;
        // if (a * b = c) {}
    }
}
