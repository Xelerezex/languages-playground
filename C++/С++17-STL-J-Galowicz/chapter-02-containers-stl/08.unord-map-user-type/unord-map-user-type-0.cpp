#include <iostream>
#include <unordered_map>

template <class K,  class V>
std::ostream& operator << (std::ostream& os, const std::unordered_map <K, V>& m);


struct coord {
    int x;
    int y;
};

std::ostream& operator << (std::ostream& os, const coord& m) {
    return os << "{" << m.x << " : " << m.y << "}";
}


bool operator == (const coord &l, const coord &r) {
    return l.x == r.x && l.y == r.y;
}


namespace std {
    template <>
    struct hash<coord>
    {
        using argument_type = coord;
        using result_type   = size_t;

        result_type operator () (const argument_type &c) const {
            return static_cast<result_type>(c.x)
                 + static_cast<result_type>(c.y);
        }
    };
}



int main() {
    std::unordered_map<coord, int> m {
        {{0, 0}, 1},
        {{0, 1}, 2},
        {{2, 1}, 3},
    };

    std::cout << m << std::endl;
}

//-------------FOR-MAP
template <class K, class V>
std::ostream& operator << (std::ostream& os,const std::unordered_map <K, V>& m) {
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
