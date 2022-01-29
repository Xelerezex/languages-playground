#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <future>
using namespace std;


int SumTwoVectors(const vector<int>& one, const vector<int>& two) {
    future<int> f = async([&one] {
        return accumulate(begin(one), end(one), 0);
    });
    int result = accumulate(begin(two), end(two), 0);
    return f.get() + result;
}

int main() {
    cout << SumTwoVectors({1, 1, 1, 1}, {3, 3, 3}) << endl;
}
