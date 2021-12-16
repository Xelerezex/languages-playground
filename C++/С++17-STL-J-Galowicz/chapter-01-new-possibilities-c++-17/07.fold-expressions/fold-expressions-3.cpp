#include <iostream>
#include <vector>
#include <algorithm>

// FUNCTION THAT FINDS ALL MATCHES STUFF IN SOME CONTAINER

template <typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts) {
    return (std::count(std::begin(range), std::end(range), ts) + ...);
}


int main() {
    std::vector<int> v {1, 2, 3, 4, 5};

    std::cout << matches(v,         2, 5) << std::endl;
    std::cout << matches(v,         100, 200) << std::endl;
    std::cout << matches("abcdefg", 'x', 'y', 'z') << std::endl;
    std::cout << matches("abcdefg", 'a', 'a', 'd', 'f') << std::endl;
}
