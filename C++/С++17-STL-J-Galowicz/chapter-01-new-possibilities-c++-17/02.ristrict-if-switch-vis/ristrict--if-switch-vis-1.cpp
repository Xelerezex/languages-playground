#include <iostream>
#include <map>


int main() {
    switch (char c (getchar()); c) {
        case 'a' : std::cout << "a\n"; break;
        case 's' : std::cout << "s\n"; break;
        case 'd' : std::cout << "d\n"; break;
        case 'w' : std::cout << "w\n"; break;

        case '0'...'9': std::cout << c << '\n'; break;
        default:
            std::cout << "NO!\n";
    }

    return 0;
}
