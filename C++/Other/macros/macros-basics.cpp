#include <iostream>
using namespace std;




#define TEST_IF_ELSE_MACRO(out, x) (out) << (x) << '\n'


#undef TEST_IF_ELSE_MACRO



int main () {

    #ifdef TEST_IF_ELSE_MACRO
        TEST_IF_ELSE_MACRO(cout, "OK!!!");
    #else
        #define OUTPUT_NO() cout << "NO!!!" << endl
        OUTPUT_NO();
        OUTPUT_NO();
    #endif

    return 0;
}
