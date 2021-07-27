#include <iostream>

using namespace std;

struct Fruit {
    int health = 0;
    string type = "fruit";
};

struct Apple : public Fruit {
    Apple() {
        health = 10;
        type = "apple";
    }
};

struct Pineapple : public Fruit {
    Pineapple() {
        health = 15;
        type = "pineapple";
    }
};

struct Orange : public Fruit {
    Orange() {
        health = 5;
        type = "orange";
    }
};

class Animal {
    public:
        Animal(const string& t = "animal") : type(t) {
        }

        void Eat(const Fruit& f) {
            cout << type << " eats " << f.type << ". " << f.health << "hp." << endl;
        }

    const string type; // !!! const
    //protected: // Only Parent or Child of class could enter that field
};

class Cat : public Animal {
    public:
        Cat() : Animal("Cat") {
        }

        void Meow() const {
            cout << "Meow!" << endl;
        }
};

class Dog : public Animal {
    public:
        Dog() : Animal("Dog") {
        }
};

void DoMeal(Animal& a, Fruit& f) {
    a.Eat(f);
}

int main() {

    Cat c;
    Dog d;

    c.Meow();

    Apple a;
    Pineapple p;
    Orange o;

    DoMeal(c, a);
    DoMeal(c, p);
    DoMeal(d, o);

    return 0;
}
