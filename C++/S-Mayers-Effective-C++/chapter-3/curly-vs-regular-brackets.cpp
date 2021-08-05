#include <iostream>


class Widget {
    public:
        Widget(int i, bool b) {
            std::cout << "First constructor" << std::endl;
        }
        Widget(int i, double d) {
            std::cout << "Second constructor" << std::endl;
        }
        Widget(std::initializer_list<long double> il) {
            std::cout << "Third constructor" << std::endl;
        }

};


int main() {

    Widget w1(10, true);
    Widget w2{10, true};

    Widget w3(10, 5.0);
    Widget w4{10, 5.0};

    return 0;
}
