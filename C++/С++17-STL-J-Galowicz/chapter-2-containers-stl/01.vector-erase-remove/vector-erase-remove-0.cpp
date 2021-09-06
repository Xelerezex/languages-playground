#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


template <class L>
ostream& operator << (ostream& os, const vector <L>& l);


// FIRST VARIANT OF ERASEMENT
int main() {
    vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};

    cout << v << " : size = " << v.size() <<endl;

    const auto new_end (remove(begin(v), end(v), 2));


    cout << v << " : size = " << v.size() << endl;

    v.erase(new_end, end(v));

    cout << v << " : size = " << v.size() << endl;
}

//-------------FOR-VECTOR
template <class L>
ostream& operator << (ostream& os, const vector <L>& l) {
    os << "[";
    bool first = true;

    for(const auto& i : l) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << i;
    }

    return os << "]";
}
