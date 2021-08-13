#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


int main() {
    std::vector<int> v {3, 4, 5, 6, 7, 9};
    auto i = upper_bound(v.begin(), v.end(), 3);

    if (i == end(v)) {  //
        // cout << "GG!" << endl; // 6
    } else if (i == begin(v)) {
        // cout << "begin : " << *i << endl;
    } else {
        // cout << *i << endl; // 6
    }

    map<int, string> Map;


    Map[1] = "One";
    Map[2] = "Two";

    auto it = Map.upper_bound(-1);

    if (it == Map.end()) {
        cout << "end()" << endl;
    } else {
        cout << it->first << " : " << it->second << endl;
    }

return 0;
}
