#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string* pS = new string;
    *pS = "Hello";
    cout << *pS << ' ' << pS->size() << endl;
    string &ref_to_s = *pS;
    ref_to_s += ", world!";
    cout << *pS << endl;
}
