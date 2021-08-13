#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;


template <class T>
ostream& operator << (ostream& os, const set <T>& s);

template <class T>
ostream& operator << (ostream& os, const vector <T>& s);


int main () {
    vector<int> Vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<int> Set = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto lrem_it = stable_partition(Vector.begin(), Vector.end(), [](const int& num){
        return num % 2 == 0;
    });

    cout << Vector << endl;

    for (auto setr = Vector.begin(); setr != lrem_it; ++setr) {
        Set.erase(*setr);
    }

    cout << Set << endl;

    return 0;
}


template <class T>
ostream& operator << (ostream& os, const set <T>& s) {
    os << "{";
    bool first = true;

    for(const auto& x : s) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << x;
    }

    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const vector <T>& s) {
    os << "[";
    bool first = true;

    for(const auto& x : s) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << x;
    }

    return os << "]";
}
