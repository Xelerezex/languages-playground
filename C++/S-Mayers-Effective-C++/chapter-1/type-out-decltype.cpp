#include <iostream>
#include <typeinfo>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    const int i = 0;
    decltype(i) j = 0;

    int a = 12;
    int& ref = a;

    cout << ref <<  endl;

    ref = ref+1;

    cout << a <<  endl;

    cout << typeid(i).name() << " " << typeid(j).name() << endl;

    return 0;
}
