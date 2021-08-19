#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main () {
    vector<string> Vector = {"One", "Two", "Three"};


    auto it = begin(Vector);
    for (; it != end(Vector); ++it) {

    }

    auto z = nullptr;

    cout << (*z) << endl;

    cout << *prev(it) << endl;


    if (it == end(Vector)) {
        cout << "2 OK!!!!" << endl;
    }


    return 0;
}
