#include <algorithm>
#include <iostream>


using namespace std;


#define SQR(x) ((x) * (x))


int LogAndReturn(int x) {
    cout << "x = " << x << endl;
    return x;
}


int main() {
    int z = SQR(LogAndReturn(3));
    cout << z << '\n';

    return 0;
}
