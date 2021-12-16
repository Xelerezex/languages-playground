#include <iostream>
#include <set>

// FUNCTION THAT CHECKS ALL ELEMENT IN SOME DIAPOSONE

template <typename T, typename ... Ts>
bool within(T min, T max, Ts ... ts) {
    return ((min <= ts && ts <= max) && ...);
}

int main() {
    std::cout << within(10, 20, 1, 15, 30) << std::endl;
    std::cout << within(10, 20, 11, 12, 13) << std::endl;
    std::cout << within(5.0, 5.5, 5.1, 5.2, 5.3) << std::endl;

    std::string aaa {"aaa"};
    std::string bcd {"bcd"};
    std::string def {"def"};
    std::string zzz {"zzz"};

    std::cout << within(aaa, zzz, bcd, def) << std::endl;
    std::cout << within(aaa, def, bcd, zzz) << std::endl;
}
