#include "tools.h"

class B
{
public:
    B() {}
    ~B() {}
};

struct owning_A
{
    B b_;
};

struct non_owning_A
{
    B& b_;
};

struct owning_A_with_ptr
{
    B *b_;

    explicit owning_A_with_ptr(B *b) : b_(b) {}

    owning_A_with_ptr(owning_A_with_ptr&& other) : b_(other.b_)
    {
        other.b_ = nullptr;
    }

    owning_A_with_ptr& operator= (owning_A_with_ptr&& other)
    {
        delete b_;
        b_ = other.b_;
        other.b_ = nullptr;
        return *this;
    }

    ~owning_A_with_ptr()
    {
        delete b_;
    }
};

struct non_owning_A_with_ptr
{
    B *b_;
};

int main()
{
    B b;

    owning_A a1 {b};

    non_owning_A a2 {b};

    owning_A_with_ptr a3 {&b};

    non_owning_A_with_ptr a4 {&b};
}
