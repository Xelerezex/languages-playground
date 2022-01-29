#include "profile.h"

#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int SIZE = 10'000;

string MakeString() {
    return "C++";
}

array<int, SIZE> MakeArray() {
    array<int, SIZE> a;
    a.fill(8);
    return a;
}

int main() {
    {
        LOG_DURATION("with variable");
        vector<array<int, SIZE>> arrays;
        for (int i = 0; i < 10'000; ++i){
            auto heavy_array = MakeArray();
            arrays.push_back(heavy_array);
        }
    }
    {
        LOG_DURATION("without variable");
        vector<array<int, SIZE>> arrays;
        for (int i = 0; i < 10'000; ++i){
            arrays.push_back(MakeArray());
        }
    }
    {
        vector<string> strings;
        const string s = MakeString();
        cout << s << "\n";
        strings.push_back(move(s));
        cout << s << "\n";
    }
    return 0;
}
