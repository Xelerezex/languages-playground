#include <iostream>
#include <vector>

template<typename T>
using TemplALias = std::vector<T>;

template<typename T>
void Print(const TemplALias<T>& t) {
    for (const auto& item : t) {
        std::cout << item << std::endl;
    }
}


int main() {
    std::vector<int> v0 = {1, 2, 3, 4, 5};
    std::vector<double> v1 = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<std::string> v2 = {"1", "2", "3", "4", "5"};


    Print(v0);
    Print(v1);
    Print(v2);


    return 0;
}
