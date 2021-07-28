#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

int main() {
    std::vector<double> z = {1, 2, 3, 4};

    std::cout << typeid(z.begin()).name() << std::endl;



    std::shared_ptr<int> p1(new int(5));
    // std::unique_ptr<int> p2(p1); Will bw error

    std::shared_ptr<int> p2(p1);


    int* p = p1.get();

    std::cout << *p << std::endl;

    return 0;
}
