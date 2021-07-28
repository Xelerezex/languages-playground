#include <iostream>

namespace first {
    void Foo() {
        std::cout << "[first]" << std::endl;
    }
}

namespace second {
    void Foo() {
        std::cout << "[second]" << std::endl;
    }
}

namespace third {
    namespace second {
        void Foo() {
            std::cout << "[third]" << std::endl;
        }
    }

    namespace fourth {
        void Foo() {
            std::cout << "[fourth]" << std::endl;
        }
    }
}

int main() {


    first::Foo();
    second::Foo();
    third::second::Foo();
    third::fourth::Foo();


    return 0;
}
