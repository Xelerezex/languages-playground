#include "profile.h"
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int NUMBER_COUNT = 1'234'567;
const int NUMBER = 1'000'000;
const int QUERY_COUNT = 10;

int main() {
    vector<int> numbers;

    for (int item = 0; item < NUMBER_COUNT; ++item) {
        numbers.push_back(item * 10);
    }

    {
        LOG_DURATION("lower_bound");
        for (int item = 0; item < QUERY_COUNT; ++item) {
            lower_bound(begin(numbers), end(numbers), NUMBER);
        }
    }

    {
        LOG_DURATION("find_if");
        for (int item = 0; item < QUERY_COUNT; ++item) {
            lower_bound(begin(numbers), end(numbers), [&](int y){ return y >= NUMBER; });
        }
    }
}
