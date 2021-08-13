#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main () {
    vector<string> one = {"one", "two", "three"};
    vector<string> two = {"four", "five"};
    vector<string> three = {"six"};
    vector<string> four = {"seven", "eight"};

    map<char, vector<string>> Map = {
        {'1', one},
        {'2', two},
        {'3', three},
        {'4', four},
    };

    for (auto it = Map.begin(); it != Map.end(); ++it) {
        for (auto it2 = (it->second).begin(); it2 != (it->second).end(); ++it2) {
            cout << (it->first) << " : " << *it2 << endl;
        }
    }


    auto iter = Map.cbegin();
    while (iter != Map.cend()) {
        if ((iter->second).size() == 1) {
            iter = Map.erase(iter);
        } else {
            ++iter;
        }
    }


    cout << "--------------------------------------------------" << endl;
    for (auto it = Map.begin(); it != Map.end(); ++it) {
        for (auto it2 = (it->second).begin(); it2 != (it->second).end(); ++it2) {
            cout << (it->first) << " : " << *it2 << endl;
        }
    }


}
