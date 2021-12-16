#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


template <class L>
ostream& operator << (ostream& os, const vector <L>& l);



// SECOND VARIANT OF ERASEMENT
int main() {
    vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
    const auto new_end (remove(begin(v), end(v), 2));

    cout << v << " : size = " << v.size() <<endl;



    const auto odd ([](int i) { return i % 2 != 0; });

    v.erase(remove_if(begin(v), end(v), odd), end(v));


    cout << v << " : size = " << v.size()  << endl;
    v.shrink_to_fit();                                     // ERASE - TO DELETE ELEMENT (VALUE), NOT TO DELETE MEMORY FROM VECTOR.
}                                                          // AFTER shrink_to_fit() - VECTOR WITH 6 ELEMENTS & 4 Empty ELEMETS
                                                           // (BUT SIZE() = 6) BECAME VECTOR WITH 6 ELEMENTS & NO EMPTY ELEMENTS

//-------------FOR-VECTOR
template <class L>
ostream& operator << (ostream& os, const vector <L>& l) {
    os << "[";
    bool first = true;

    for(const auto& i : l) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << i;
    }

    return os << "]";
}

