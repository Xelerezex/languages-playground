#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int main () {
    deque<string> dq;
    dq.push_front("August");
    dq.push_front("Benchmark");
    dq.push_front("Ciri");
    dq.push_front("Denny");


    for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
        cout << *it << endl;
    }

}
