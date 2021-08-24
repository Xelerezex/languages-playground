#include <iostream>
using namespace std;




#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)


int main () {
    int value = 10;
    cout << STR(value) << endl;
    return 0;
}
