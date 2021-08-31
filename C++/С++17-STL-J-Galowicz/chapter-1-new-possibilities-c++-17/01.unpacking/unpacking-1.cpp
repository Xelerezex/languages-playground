#include <iostream>
#include <utility>


std::pair<int, int> divide_remainder(int dividend, int divisor) {
    return std::make_pair(dividend/divisor, dividend%divisor);
}


int main() {

    // SECOND WAY - TO GET TWO VALUES OUT OF PAIR:
    auto [fraction, remainder] = (divide_remainder(16, 3));


    std::cout << "16 / 3 is "
              << fraction << " with a remainder of "
              << remainder << '\n';

    return 0;
}
