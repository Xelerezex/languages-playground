#include <iostream>

uint64_t EuclidGCD(uint64_t first, uint64_t second) {
    return (second == 0) ? first : EuclidGCD(second, first % second);
}

int main() {
    uint64_t a = 6, b = 8;
    std::cout << EuclidGCD(a, b) << '\n';
}
