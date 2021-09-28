#include <iostream>

int Fibonacci(int number) {
    return (number <= 1) ? number : (Fibonacci(number - 1) + Fibonacci(number - 2));
}

int main() {
    int n = 45;
    std::cout << Fibonacci(n) << '\n';
}

// 1134903170
// [Finished in 7.8s]
