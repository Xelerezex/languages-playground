#include <iostream>

uint64_t gcd(uint64_t first, uint64_t second) {
    uint64_t gcd = 0;
    for (uint64_t num = 1; num <= (first + second); ++num) {
        if ((first % num == 0) && (second % num == 0)) {
            gcd = num;
        }
    }
    return gcd;
}

int main() {
    uint64_t a = 28851538, b = 1183019;
    std::cout << gcd(a, b) << '\n';
}
