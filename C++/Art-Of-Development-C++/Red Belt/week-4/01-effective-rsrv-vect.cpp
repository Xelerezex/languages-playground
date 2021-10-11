#include <iostream>
#include <vector>
#include "profile.h"

using namespace std;

int main() {
    int vec_size = 100'000'000;
    {
        LOG_DURATION("push_back");
        vector<int> v;
        for (int i = 0; i < vec_size; ++i) {
            v.push_back(i);
        }
    }
    {
        LOG_DURATION("push_back & reverse");
        vector<int> v;
        v.reserve(vec_size);
        for (int i = 0; i < vec_size; ++i) {
            v.push_back(i);
        }
    }
}
