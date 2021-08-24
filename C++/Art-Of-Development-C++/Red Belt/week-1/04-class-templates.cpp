#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

int main() {
    Pair<string, int> si;
    si.first = "5";
    si.second = 5;

    return 0;
}
