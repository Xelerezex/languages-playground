#include <iostream>

uint64_t EuclidGCD(uint64_t first, uint64_t second) {
    return (second == 0) ? first : EuclidGCD(second, first % second);
}

uint64_t LCM(uint64_t first, uint64_t second) {
    uint64_t gcd       = EuclidGCD(first, second),
             f_div_gcd = first  / gcd,
             s_div_gcd = second / gcd;

    return gcd * f_div_gcd * s_div_gcd;
}

int main() {
    uint64_t a = 28851538, b = 1183019;
    std::cout << ((LCM(a, b) == 1933053046) ? "true": "false") << '\n';
}
