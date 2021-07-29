#include <iostream>
#include <fstream>
#include <sstream>


std::string CreateFigure(std::istringstream& is) {
    std::string name;
    double one, two;

    is >> name >> one >> two;

    std::cout << name << " " << one << " " << two << std::endl << std::endl;

    return is.str();
}

int main() {
    std::string line, command;

    getline(std::cin, line);
    std::istringstream is(line);

    is >> command;
    is >> std::ws;

    std::cout << CreateFigure(is) << std::endl;

    return 0;
}
