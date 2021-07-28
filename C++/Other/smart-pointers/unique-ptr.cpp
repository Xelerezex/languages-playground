#include <iostream>
#include <memory>

int main() {

    std::unique_ptr<int> p1(new int(5));
    // std::unique_ptr<int> p2(p1); Will bw error

    std::unique_ptr<int> p2;

    //p2.release(); delete data

    int* p = p1.get();

    std::cout << *p << std::endl;

    return 0;
}
