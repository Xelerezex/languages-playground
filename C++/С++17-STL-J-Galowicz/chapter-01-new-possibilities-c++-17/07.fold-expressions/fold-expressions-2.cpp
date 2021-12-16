#include <iostream>

template <typename ... Ts>
auto product(Ts ... ts) {
    return (ts * ... * 1);
}

int main() {
    int the_sum {sum(1, 2, 3, 4, 5)};
    std::cout << the_sum << std::endl;
    std::cout << sum() << std::endl;
}
