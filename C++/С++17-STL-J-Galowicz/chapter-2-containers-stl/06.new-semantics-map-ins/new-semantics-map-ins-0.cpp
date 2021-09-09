#include <iostream>
#include <map>
#include <string>

template <class K,  class V>
std::ostream& operator << (std::ostream& os, const std::map <K, V>& m);

int main() {
    std::map<std::string, size_t> m {
        {"b", 1},
        {"c", 2},
        {"d", 3},
    };

    auto insert_it (std::end(m));

    m.insert(std::end(m), {"a", 1});
    for (const auto &s : {"z", "y", "x", "w"}) {
        insert_it = m.insert(insert_it, {s, 1});
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
