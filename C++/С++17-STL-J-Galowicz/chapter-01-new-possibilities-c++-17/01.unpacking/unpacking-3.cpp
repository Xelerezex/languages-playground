#include <iostream>
#include <string>
#include <vector>


struct employee {
    unsigned id;
    std::string name;
    std::string role;
    unsigned salary;
};


int main() {

    std::vector<employee> employees {
        {1, "John", "Johnson", 1'600},
        {2, "John", "Doe", 9'999},
    };


    for (const auto &[id, name, role, salary] : employees){
            // THIRD WAY - GET TWO VALUES OUT OF STRUCTURE:
        std::cout << "Name: "   << name   << '\n'
                  << "Role: "   << role   << '\n'
                  << "Salary: " << salary << '\n' << '\n';
    }


    return 0;
}
