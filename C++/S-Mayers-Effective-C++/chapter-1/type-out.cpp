#include <iostream>
#include <typeinfo>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int x = 27;          // x -> int
    const int cx = x;    // cx -> const int
    const int* const rx = &x;   // rx -> reference on x, with type const int

    cout << x << " " << cx << " " << rx << endl;
    cout << typeid(x).name() << " | " << typeid(cx).name() << " | " << typeid(rx).name()  << endl;

    auto variable1{10};

    cout << variable1 << endl;
    cout << typeid(variable1).name() << endl;

    return 0;
}
