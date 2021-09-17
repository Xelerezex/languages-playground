#include "profile.h"
#include <deque>
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> numbers;

    for (int item = 0; item < 3'000'000; ++item) {
        numbers.insert(item);
    }

    const int x = 1'234'567;

    {
        LOG_DURATION("GLOBAL lower_bound");
        cout << *lower_bound(begin(numbers), end(numbers), x) << endl;
    }

    {
        LOG_DURATION("SET lower_bound");
        cout << *numbers.lower_bound(x) << endl;
    }
}
