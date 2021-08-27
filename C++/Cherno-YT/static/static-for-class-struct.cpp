#include <iostream>

struct Entity {
    static int x, y;


    // Static MEthod only enters static variable
    static void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

int main() {



    Entity::x = 2;
    Entity::y = 3;

    Entity::Print();


    Entity::x = 5;
    Entity::y = 8;


    Entity::Print();
    Entity::Print();

    return 0;
}
