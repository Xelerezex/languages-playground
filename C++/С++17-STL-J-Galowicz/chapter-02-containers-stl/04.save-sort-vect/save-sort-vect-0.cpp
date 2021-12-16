#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l);

template<typename C, typename T>
void insert_sorted(C &v, const T &word);

int main() {
    std::vector<std::string> v {"some", "random", "words",
                                "without", "order", "aaa",
                                "yyy"};

    assert(false == std::is_sorted(begin(v), end(v)));
    std::sort(begin(v), end(v));
    assert(true == std::is_sorted(begin(v), end(v)));

    insert_sorted(v, "foobar");
    insert_sorted(v, "zzz");

    std::cout << v << std::endl;
}


template<typename C, typename T>
void insert_sorted(C &v, const T &word) {
    const auto insert_pos (lower_bound(begin(v), end(v), word));
    v.insert(insert_pos, word);
}


//-------------FOR-VECTOR
template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l) {
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
