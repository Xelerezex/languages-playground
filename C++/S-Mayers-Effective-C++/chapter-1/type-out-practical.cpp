// Function typeid can not give to us fully right output
// Just remember it

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

template<typename>
class TD;

class Widget {};

template<typename T>
void f(const T& param);

std::vector<Widget> createWec();

int main() {
// FIRST VARIANT

    const int theAnswer = 42;
    auto x = theAnswer;
    auto y = &theAnswer;

/*  Creating error for types output

    TD<decltype(x)> xType;
    TD<decltype(y)> yType;

*/

/* Our error:

    type-out-practical.cpp:13:21: error: aggregate ‘TD<int> xType’ has incomplete type and cannot be defined
   13 |     TD<decltype(x)> xType;
      |                     ^~~~~
    type-out-practical.cpp:14:21: error: aggregate ‘TD<const int*> yType’ has incomplete type and cannot be defined
   14 |     TD<decltype(y)> yType;
      |

*/

// SECOND VARIANT

    std::cout << typeid(x).name() << '\n';  // Output of types   | if c++filt -t at the end of g++ command
    std::cout << typeid(y).name() << '\n';  // for x & y         | (after .cpp file). Outputs will be:
                                            //                   | int, int const*

// THIRD VARIANT



    const auto vw = createWec();

    if(!vw.empty()) {
        f(&vw[0]);
    }

    return 0;
}


template<typename T>
void f(const T& param) {
    using std::cout;

    cout << "T = " << typeid(T).name() << '\n';             // PK - Pointer(P) on Constant(K)

    cout << "param = " << typeid(param).name() << '\n';
}


std::vector<Widget> createWec() {
    Widget w;
    std::vector<Widget> vw(2);
    vw.push_back(w);
    vw.push_back(w);
    return vw;
}
