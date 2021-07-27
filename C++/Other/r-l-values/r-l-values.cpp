#include <iostream>

void PrintName(const std::string& name) {
    std::cout << "[lvalue] " << name << std::endl;
}

void PrintName(const std::string&& name) {
    std::cout << "[rvalue] " << name << std::endl;
}

int main() {
    std::string firstName = "Nikita";
    std::string lastName = "Valderman";

    std::string fullName = firstName + lastName;

    PrintName(fullName);
    PrintName(firstName + lastName);
    return 0;
}
