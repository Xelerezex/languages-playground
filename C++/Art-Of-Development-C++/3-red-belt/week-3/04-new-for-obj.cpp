#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Widget {
    Widget() {
        cout << "Constructor" << endl;
    }

    ~Widget() {
        cout << "Destructor" << endl;
    }
};

int main() {
    Widget* w = new Widget;
    delete w;
}
