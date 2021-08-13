#include <iostream>
#include <vector>
#include <set>


using namespace std;


template <class L>
ostream& operator << (ostream& os, const vector <L>& l);

void PushUnique(vector<int>& vect, int&& val) {
    static set<int> temporary;
    auto input = temporary.insert(val);

    cout << *input.first << ":" << input.second << (input.second ? "true" : "false") << endl;

    if (input.second != false) {
        vect.push_back(*input.first);
    }

}
int main() {
    vector<int> Vector;
    cout << Vector << endl;


    PushUnique(Vector, 1);
    PushUnique(Vector, 1);
    PushUnique(Vector, 1);
    PushUnique(Vector, 2);
    PushUnique(Vector, 2);
    PushUnique(Vector, 2);
    PushUnique(Vector, 3);
    PushUnique(Vector, 3);
    PushUnique(Vector, 3);


    cout << Vector << endl;
    return 0;
}



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
