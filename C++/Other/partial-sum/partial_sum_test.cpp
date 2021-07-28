#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <chrono>

using namespace std;

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

    return os << "]" << "\tvector\tsize:" << l.size();
}

int main() {

    vector<uint64_t> money = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<uint64_t> partial_sums(10, 0);

    cout << money << endl;

    partial_sum(money.begin(), money.end(), partial_sums.begin());

    cout << partial_sums << endl;

    return 0;
}
