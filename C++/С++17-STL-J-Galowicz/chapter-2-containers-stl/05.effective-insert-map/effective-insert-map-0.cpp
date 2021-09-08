#include <iostream>
#include <functional>
#include <list>
#include <map>


template <class K,  class V>
std::ostream& operator << (std::ostream& os, const std::map    <K, V>& m);

struct billionaire {
    std::string name;
    double dollars;
    std::string country;
};

int main() {
    std::list<billionaire> billionaires {
        {"Bill Gates", 86.0, "USA"},
        {"Warren Buffet", 75.6, "USA"},
        {"Jeff Bezos", 72.8, "USA"},
        {"Amancio Ortega", 71.3, "Spain"},
        {"Carlos Slim", 54.5, "Mexico"},
    };

    std::map<std::string, std::pair<const billionaire, size_t>> m;

    for (const auto &b : billionaires) {
        auto [iterator, success] = m.try_emplace(b.country, b, 1);
        if (!success) {
            iterator -> second.second += 1;
        }
    }

    for (const auto & [key, value] : m) {
        const auto &[b, count] = value;
        std::cout << b.country << " : " << count
             << " billionaries. Richiest is "
             << b.name << " with " << b.dollars
             << " B$\n";
    }
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
