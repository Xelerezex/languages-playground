#include <iostream>
#include <string>
#include <vector>
#include "profile.h"

using namespace std;

string MakeString() {
    return string(500'000'000, 'a');
}

int main() {
    {
        LOG_DURATION("with variable")
        vector<string> strings;
        string heavy_string = MakeString();
        strings.push_back(heavy_string);
    }
    {
        LOG_DURATION("without variable")
        vector<string> strings;
        strings.push_back(MakeString());
    }
    {
        LOG_DURATION("with variable, without function")
        vector<string> strings;
        string heavy_string = string(500'000'000, 'a');
        strings.push_back(heavy_string);
    }
    {
        LOG_DURATION("without variable, without function")
        vector<string> strings;
        strings.push_back(string(500'000'000, 'a'));
    }
    return 0;
}
