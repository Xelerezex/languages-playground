#include <iostream>

using namespace std;

int main () {
    int z = 5;
    auto func = [z](const int& G) {cout << z + G << " DONE!\n";};

    return 0;
}
