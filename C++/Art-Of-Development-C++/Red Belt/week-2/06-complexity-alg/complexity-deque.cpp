#include "profile.h"
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    {
        LOG_DURATION("VECTOR");
        vector<int> v;
        for (int item = 0; item < 100'000; ++item) {
            v.insert(begin(v), item);
        }
    }

    {
        LOG_DURATION("DEQUE ");
        deque<int> d;
        for (int item = 0; item < 100'000; ++item) {
            d.push_front(item);
        }
    }
}
