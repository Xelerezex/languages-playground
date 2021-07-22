#include <iostream>

using namespace std;

int main() {

    uint64_t variable = 42;

    uint64_t* pointer_to_variable = &variable;

    cout << pointer_to_variable << " " << sizeof(pointer_to_variable) << endl << pointer_to_variable + 1 << " " << sizeof(pointer_to_variable + 1) << endl;

    return 0;
}
