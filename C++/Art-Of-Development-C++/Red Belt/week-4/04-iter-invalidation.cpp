#include "profile.h"
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    {
        vector<int> numbers = {1};
        auto it = begin(numbers);
        cout << *it << "\n";

        for (int i = 0; i < 2'000; ++i) {
            numbers.push_back(i);
        }
        cout << *it << "\n";
    }
    {
        deque<int> numbers = {1};
        auto it = begin(numbers);
        cout << *it << "\n";

        for (int i = 0; i < 2'000; ++i) {
            numbers.push_back(i);
        }

        cout << *it << " " << *(it + numbers.size() -1 ) << "\n";
    }
}
