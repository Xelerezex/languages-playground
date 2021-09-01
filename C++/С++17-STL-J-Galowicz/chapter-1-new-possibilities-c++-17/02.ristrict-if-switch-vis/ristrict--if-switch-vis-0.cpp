#include <iostream>
#include <map>


int main() {
    std::map<char, int> character_map = {
        {'a', 5},
        {'b', 7},
        {'c', 1},
        {'d', 1},
    };

    if (auto itr (character_map.find('c')); itr != character_map.end()) {
        std::cout << itr->first << " : " << itr->second << '\n';
    } else {
        std::cout << "NOT IN MAP!" << '\n';
    }

    return 0;
}
