#include <iostream>
#include <cstdint>

enum class Command : std::string {
    One,
    Two,
};



enum Commands : std::uint8_t {
    One,
    Two,
    Three,
    Four,
    Five,
};


int main() {

    Command c = Command::One;
    // std::cout << Command::One << std::endl; --> Error


    switch(c){
        case(Command::One):
            std::cout << 1 << std::endl;
    };


    std::cout << Commands::Two << std::endl;

    return 0;
}
