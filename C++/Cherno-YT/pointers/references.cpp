#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

int main () {

    int variable = 42;

    int& reference = variable;

    ++reference;        // By reference change exact variable

    LOG(reference);
    LOG(variable);

    return 0;
}
