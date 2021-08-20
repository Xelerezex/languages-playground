#include <iostream>
#include <iomanip>
#include <string>


using namespace std;


#define AS_KV(x) #x << " = " << x


int main() {
    int x = 4;
    string t = "hello";
    bool isTrue = false;

    cerr << boolalpha;
    cerr << AS_KV(x) << endl
         << AS_KV(t) << endl
         << AS_KV(isTrue) << endl;

    return 0;
}
