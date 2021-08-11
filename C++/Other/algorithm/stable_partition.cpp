#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l);

int main() {

    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec2 = {1, 0, 3, 4, 5, 5, 7, 8, 9};

    cout << vec1 << endl;
    cout << vec2 << endl;

    auto it0 = stable_partition(vec1.begin(), vec1.end(), [](const int numb){
        return numb == 0;
    });
    auto it = stable_partition(vec2.begin(), vec2.end(), [](const int numb){
        return numb == 0;
    });

    vec2.erase(vec2.begin(), (vec2.begin()+1));

    cout << "------------------------------------" << endl;
    cout << vec1 <<"\t" << ((*it0 /*== (vec1.end() - 1) */)/* ? "true" : "false"*/) << endl;
    cout << vec2 << "\t" <<*it << endl;

    vec2.push_back(666);

    cout << vec2 << endl;

    return 0;
}


template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l) {
    os << "v[";
    bool first = true;

    for(const auto& i : l) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << i;
    }

    return os << "]" << " size:" << l.size();
}
