// Rule #33
// Don't hide inherited names

class Base
{
    private:
        int x;

    public:
        virtual void mf1() = 0;
        virtual void mf1(int);

        virtual void mf2() {}

        void mf3() {}
        void mf3(double) {}
};

class Derived : public Base
{
    public:
        virtual void mf1();
        void mf3() {}
        void mf4() {}
};


int main()
{
    Derived d;
    int x;

    d.mf1();
    // d.mf1(x);

    d.mf2();

    d.mf3();
    // d.mf1(x);
}
