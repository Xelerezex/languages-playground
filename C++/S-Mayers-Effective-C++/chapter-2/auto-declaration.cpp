#include <iostream>
#include <vector>


/*
template<typename It>
void dwim(It b, It e) {
    while (b != e) {
        typename std::iterator_traits<It>::value_type currValue = *b;
    }
}
*/


// ANALOG:

template<typename It>
void dwim(It b, It e) {
    while (b != e) {
        auto currValue = *b;
    }
}


int main() {
    std::vector<int> v;

    /*unsigned sz = v.size();  // MISTAKE. Doesn't right!*/

    std::vector<int>::size_type sz0 = v.size();

    // OR:


    auto sz1 = v.size();

    return 0;
}
