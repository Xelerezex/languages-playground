#include <iostream>
#include <vector>
#include <boost/type_index.hpp>


class Widget {};


std::vector<bool> features(const Widget& w);

template<typename T>
void processWidget(const Widget& w, T& Hp);


int main() {

    Widget w;

    // WORK FINE:
    /* bool highPriority = features(w)[5]; */

    // UNDEFINED BEHAVIOR:
    auto highPriority = features(w)[5];  // TYPE: std::_Bit_reference
                                         // AN IMPLICIT CONVERSION OCCURS (bool)

    // THE IDIOM OF EXPLICIT TYPING:
    /*auto highPriority = static_cast<bool>(features(w)[5]);*/

    processWidget(w, highPriority);

    return 0;
}


std::vector<bool> features(const Widget& w) {
    return {false, false, true, false, true, true, false, false};
}

template<typename T>
void processWidget(const Widget& w, T& Hp) {
    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    cout << "w     =  "
         << type_id_with_cvr<decltype(w)>().pretty_name()
         << '\n';

    cout << "Hp    =  "
         << type_id_with_cvr<T>().pretty_name()
         << '\n';
}
