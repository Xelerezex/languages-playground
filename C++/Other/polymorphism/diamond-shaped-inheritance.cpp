#include <iostream>

class Component {
    public:
        Component(std::string compName) {
            std::cout << "Constr Component" << std::endl;
            this -> compName = compName;
        }
        std::string compName;
};

class GPU : public Component {
    public:
        GPU(std::string compName) : Component(compName) {
            std::cout << "Constr GPU" << std::endl;
        }
};

class Memory : public Component {
    public:
        Memory(std::string compName) : Component(compName) {
            std::cout << "Constr Memory" << std::endl;
        }
};

class GraphicCard : public GPU, public Memory {
    public:
        GraphicCard(std::string GPUCompName, std::string MemoryCompName) : GPU(GPUCompName), Memory(MemoryCompName) {
            std::cout << "Constr GraphicCard" << std::endl;
        }
};

auto f(float a) -> float {
    return a;
}

int main() {
    GraphicCard gc("AMD", "Samsung");

    float a = 10.10000;
    std::cout << f(a) << std::endl;

    return 0;
}
