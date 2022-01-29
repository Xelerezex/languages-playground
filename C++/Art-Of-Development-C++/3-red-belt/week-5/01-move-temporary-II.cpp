#include "profile.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>


using namespace std;

string MakeString() {
    return string(300'000'000, 'a');
}

vector<int> MakeVector() {
    return vector<int>(100'000'000, 0);
}

int main() {
    {
        LOG_DURATION("assignment, with variable")
        string target_string = "old value";
        string source_string = MakeString();
        target_string = source_string;
    }
    {
        LOG_DURATION("assignment, without variable")
        string target_string = "old value";
        target_string = MakeString();
    }

    {
        LOG_DURATION("set::insert, with variable")
        set<string> strings;
        string heavy_string = MakeString();
        strings.insert(heavy_string);
    }
    {
        LOG_DURATION("set::insert, without variable")
        set<string> strings;
        strings.insert(MakeString());
    }

    {
        LOG_DURATION("map::operator[], with variable")
        map<string, string> strings;
        string key = MakeString();
        string value = MakeString();
        strings[key] = value;
    }
    {
        LOG_DURATION("map::operator[], without variable")
        map<string, string> strings;
        strings[MakeString()] = MakeString();
    }

    {
        LOG_DURATION("set::insert for vector, with variable")
        set<vector<int>> vectors;
        vector<int> heavy_vector = MakeVector();
        vectors.insert(heavy_vector);
    }
    {
        LOG_DURATION("set::insert for vector, without variable")
        set<vector<int>> vectors;
        vectors.insert(MakeVector());
    }
    return 0;
}
