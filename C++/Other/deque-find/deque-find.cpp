#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int main () {
    deque<int> dq;
    dq.push_front(1);
    dq.push_front(3);
    dq.push_front(6);
    dq.push_front(9);
    dq.push_front(13);
    dq.push_front(17);

    int a = 5;
    int b = 18;

    auto it1 = find(dq.begin(), dq.end(), a);
    auto it2 = find(dq.begin(), dq.end(), b);

    (it1 != dq.end())
        ? cout << "dq contains " << a << '\n'
        : cout << "dq does not contain " << a << '\n';


    (it2 != dq.end())
        ? cout << "dq contains " << b << '\n'
        : cout << "dq does not contain " << b << '\n';



    for (auto it = dq.front(); it != (dq.back()); --it) {
        cout << it << endl;
    }

}
