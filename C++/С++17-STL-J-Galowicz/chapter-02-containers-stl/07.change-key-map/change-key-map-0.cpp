#include <iostream>
#include <map>

template <class K,  class V>
std::ostream& operator << (std::ostream& os, const std::map <K, V>& m);

int main() {
    std::map<int, std::string> m {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
    };

    {
        auto a (m.extract(3));
        auto b (m.extract(8));

        std::swap(a.key(), b.key());

        m.insert(move(a));
        m.insert(move(b));
    }

    std::cout << m << std::endl;

}

//-------------FOR-MAP
template <class K, class V>
std::ostream& operator << (std::ostream& os,const std::map <K, V>& m) {
    os <<"{";
    bool first = true;

    for(const auto& kv : m) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << kv.first << ": " << kv.second;

    }
    return os <<"}";
}
