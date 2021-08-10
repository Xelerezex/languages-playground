#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;



template <typename I, typename S>
ostream& operator << (ostream& os, const pair<I, S>& pr){
    return os << pr.first << " : " << pr.second;
}


template <typename S>
ostream& operator << (ostream& os, const vector<S>& s){
    os << "{" << endl;
    for (const auto& item : s) {
        os << "<" << item << ">" << endl;
    }
    return os << endl << "}";
}






int main() {
    vector<pair<int, string>> SomeVect;

    SomeVect.push_back(make_pair(3, "FIRST"));
    SomeVect.push_back(make_pair(2, "Two"));
    SomeVect.push_back(make_pair(0, "Zero"));
    SomeVect.push_back(make_pair(3, "SECOND"));
    SomeVect.push_back(make_pair(3, "FOURTH"));
    SomeVect.push_back(make_pair(1, "One"));
    SomeVect.push_back(make_pair(4, "Four"));
    SomeVect.push_back(make_pair(3, "THIRD"));
    SomeVect.push_back(make_pair(5, "FIRST"));

    sort(SomeVect.begin(), SomeVect.end(), [](auto lhs, auto rhs){
        return lhs.first < rhs.first;
    });

    if (make_pair(5, "F") != make_pair(5, "F")) {
        cout << "GG!" << endl;
    }

    cout << SomeVect;
    return 0;
}
