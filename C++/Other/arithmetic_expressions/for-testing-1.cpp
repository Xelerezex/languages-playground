#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <cstdint>

#include "container_cout.h"

int main() {
    std::stack<std::string> values;
    std::stack<std::string> ops;

    values.push("1");values.push("2");values.push("3");values.push("4");values.push("5");

    std::cout << values << std::endl;

    return 0;
}
