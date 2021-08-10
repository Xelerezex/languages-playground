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

/*

        auto data   = (iter->first);
        auto events = (iter->second);
        size_t old_events_qua = events.size();

        if (events.size() < 2) {
            iter = DataBaseStorage.erase(iter);

            number_out += 1;
        } else {
            auto new_end = remove_if(events.begin(), events.end(), [data, func](string event){
                return func(data, event);
            });

            events.erase(new_end, events.end());

            number_out += (old_events_qua - events.size());

            ++iter;
        }
*/
