#include <iostream>
#include <typeinfo>

template<class T>
class Test {
    public:
        Test(T& val) : value(val) {}

        void Size() {
            std::cout << sizeof(value) << " byte. " << typeid(value).name() << " type." << std::endl;
        }
    protected:
        T value;
};

template<class T>
class Value : public Test<T>{
    public:
        Value(T& val) : Test<T>(val), value(val) {}

        void Out() {
            std::cout << value << std::endl;
        }
    private:
        T value;
};

int main() {

    double a = 10.10101010;

    Value<double> t(a);
    t.Size();
    t.Out();


    return 0;
}
