#include <iostream>
#include <string>
#include <utility>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    vector<string> toremove = {"a", "b", "c", "1", "2", "d", "f", "3", "g", "4", "5"};

    size_t old_size = toremove.size();

    auto new_it = remove_if(toremove.begin(), toremove.end(), [](string val){
        return isdigit(val[0]);
    });

    toremove.erase(new_it, toremove.end());


    for (auto it = toremove.begin(); it != toremove.end(); ++it) {
        if ((*it).empty()) {
            cout << "!!" << endl;
        } else {
            cout << *it << endl;
        }
    }

    cout << endl << (old_size - toremove.size()) << endl;

}
