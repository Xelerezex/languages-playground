#include <iostream>
#include <string>

template <typename ... Ts>
auto sum(Ts ... ts) {
    return (ts + ...);
}

int main() {
    int the_sum {sum(1, 2, 3, 4, 5)};
    std::cout << the_sum << std::endl;

    std::string a {"Hello "};
    std::string b {"World"};
    std::cout << sum(a, b) << '\n';
}
