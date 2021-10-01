#include <iostream>
#include <string>

class Entity {
    private:
        std::string m_Name;
        mutable int m_DebugCount = 0;           // NOW WE COULD CHANGE THAT VARIABLE IN CONST METHOD
    public:
        const std::string& GetName() const {
            m_DebugCount++;
            return m_Name;
        }
};

int main() {
    const Entity e;
    e.GetName();

    int x = 8;
    auto f = [x]() mutable {  // x - GET IN LAMBDA BY VALUE, IF WE'D LIKE TO CHANGE IT - WE SHOULD MAKE f  MUTABLE
        x++;
        std::cout << "Lambda: " << x << '\n';
    };

    f();

    std::cout << "Main: " << x << '\n';

}
