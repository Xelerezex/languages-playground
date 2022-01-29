#include "profile.h"
#include "test_runner.h"

using namespace std;

int main() {
    int x = 111111;
    array<int, 10> numbers;
    numbers.fill(8);
    int y = 222222;

    for (int* p = &y; p <= &x; ++p) {
        cout << *p << " ";
    } cout << '\n';

}
