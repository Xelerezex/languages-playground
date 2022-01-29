#include "tools.h"

struct Visitor
{
    double operator() (double d)
    {
        return d;
    }

    double operator() (int i)
    {
        return double(i);
    }

    double operator() (const std::string&)
    {
        return -1;
    }
};

using Var = std::variant<int, double, std::string>;

void show(Var v)
{
    std::cout << std::visit(Visitor{}, v) << std::endl;
}

struct MultiVisitor
{
    template<class T, class U, class V>
    void operator() (T, U, V) const { puts("wrong"); }

    void operator() (char, int, double) const { puts("right!"); }
};

struct A
{
    A() { throw "ha ha!"; }
};

struct B
{
    operator int () { throw "ha ha!"; }
};

struct C
{
    C() = default;
    C& operator=(C&&) = default;
    C(C&&) { throw "ha ha!"; }
};

int main()
{
    {
        std::variant<int, double> v1;

        v1 = 1;
        ASSERT_EQUAL(v1.index(), 0U);
        ASSERT_EQUAL(std::get<0>(v1), 1);

        v1 = 3.14;
        ASSERT_EQUAL(v1.index(), 1U);
        ASSERT_EQUAL(std::get<1>(v1), 3.14);
        ASSERT_EQUAL(std::get<double>(v1), 3.14);

        ASSERT_EQUAL(std::holds_alternative<int>(v1), false);
        ASSERT_EQUAL(std::holds_alternative<double>(v1), true);

        ASSERT_EQUAL(std::get_if<int>(&v1), nullptr);
        ASSERT_EQUAL(*std::get_if<double>(&v1), 3.14);

        try
        {
            std::cout << std::get<int>(v1) << std::endl;
        }
        catch (const std::bad_variant_access&)
        {
            std::cout << "catched: std::bad_variant_access" << std::endl;
        }

        if (v1.index() == 0)
        {
            std::cout << std::get<int>(v1) << std::endl;
        }

        if (std::holds_alternative<int>(v1))
        {
            std::cout << std::get<int>(v1) << std::endl;
        }

        if (int *p = std::get_if<int>(&v1))
        {
            std::cout << *p << std::endl;
        }
    }
    {
        show(3.14);
        show(1);
        show("hello world");
    }
    {
        std::variant<int, double, char> v1 = 'x';
        std::variant<char, int, double> v2 = 1;
        std::variant<double, char, int> v3 = 3.14;
        std::visit(MultiVisitor{}, v1, v2, v3);
    }
    {
        std::variant<int, A, C> v1 = 42;

        try
        {
            v1.emplace<A>();
        }
        catch (const char *haha)
        {
        }

        assert(v1.valueless_by_exception() == 0);

        try
        {
            v1.emplace<int>(B());
        }
        catch (const char *haha)
        {
        }

        assert(v1.valueless_by_exception() == 0);

        v1 = 42;

        try
        {
            v1 = A();
        }
        catch (...)
        {

        }

        assert(std::get<int>(v1) == 42);


        try
        {
            v1 = B();
        }
        catch (...)
        {

        }

        assert(std::get<int>(v1) == 42);

        try
        {
            v1 = C();
        }
        catch (...)
        {

        }

        assert(v1.valueless_by_exception());
    }
}
