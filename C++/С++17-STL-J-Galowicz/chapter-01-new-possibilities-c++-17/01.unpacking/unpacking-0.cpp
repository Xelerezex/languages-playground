#include <iostream>
#include <utility>
#include <tuple>


std::pair<int, int> divide_remainder(int dividend, int divisor) {
    return std::make_pair(dividend/divisor, dividend%divisor);
}


int main() {

    // FIRST WAY - TO GET TWO VALUES OUT OF PAIR:
    const auto result (divide_remainder(16, 3));


    std::cout << "16 / 3 is "
              << result.first << " with a remainder of "
              << result.second << '\n';


    // IN PREVIOUS VERSION (OLDER THAN C++17):
    int remainder;
    std::tie(std::ignore, remainder) = divide_remainder(16, 5);
        std::cout << "16 / 3 is "
              << result.first << " with a remainder of "
              << result.second << '\n';

    return 0;
}
