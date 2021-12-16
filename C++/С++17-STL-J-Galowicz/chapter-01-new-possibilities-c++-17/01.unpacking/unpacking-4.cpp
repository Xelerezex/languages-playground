#include <iostream>
#include <string>
#include <map>


int main() {

    std::map<std::string, size_t> animal_population {
        {"humans", 7'000'000'000},
        {"chickens", 17'863'376'000},
        {"camels", 24'246'291},
    };


    for (const auto &[species, count] : animal_population){
                // FOURTH EXAMPLE:
            std::cout << "There are " << count << " " << species
                      << " on this planet.\n";
        }


    return 0;
}
