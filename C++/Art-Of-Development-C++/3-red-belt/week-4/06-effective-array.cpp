#include "profile.h"
#include "test_runner.h"

using namespace std;

vector<int> BuildVector(int i) {
    return {i, i + 1, i + 2, i + 3, i + 4};
}

tuple<int, int, int, int, int> BuildTuple(int i) {
    return make_tuple(i, i + 1, i + 2, i + 3, i + 4);
}

array<int, 5> BuildArray(int i) {
    return {i, i + 1, i + 2, i + 3, i + 4};
}

const int COUNT = 100'000'000;

int main() {
    {
        LOG_DURATION("Vector")
        for (int i = 0; i < COUNT; ++i) {
            auto numbers = BuildVector(i);
            if(numbers.size() != 1) {}
        }
    }
    {
        LOG_DURATION("Tuple")
        for (int i = 0; i < COUNT; ++i) {
            auto numbers = BuildTuple(i);
            if(get<0>(numbers) == 1) {}
        }
    }
    {
        LOG_DURATION("Array")
        for (int i = 0; i < COUNT; ++i) {
            auto numbers = BuildArray(i);
            sort (begin(numbers), end(numbers));
        }
    }
}
