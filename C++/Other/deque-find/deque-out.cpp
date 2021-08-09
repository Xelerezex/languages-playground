#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    vector<string> matches;

    vector<string> dq;
    string str1 = "Benchmark", str2 = "VaVa", str3 = "QQ";

    dq.push_back("August");
    dq.push_back(str2);
    dq.push_back(str1);
    dq.push_back(str3);
    dq.push_back("Ciri");
    dq.push_back("Denny");



    remove_if(dq.begin(), dq.end(), [&](string val){return ((val == str2) || (val == str1) || (val == str3)) ;});

    copy_if(dq.begin(), dq.end(), std::back_inserter(matches), [](string val) {
        return val.empty();
    });

    cout << matches.size() << endl;

    for (auto it = dq.begin(); it != dq.end(); ++it) {
        if ((*it).empty()) {
            cout << "!!" << endl;
        } else {
            cout << *it << endl;
        }
    }
}
