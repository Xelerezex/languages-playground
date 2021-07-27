#include <iostream>

using namespace std;

class Animal {
    public:
        Animal(const string& type = "animal") : type_(type) {
        }

        void Eat(const string str) {
            cout << type_ << " eats " << str << ". " << endl;
        }

        virtual void Sound() const /* = 0; */ {
            cout << type_ << " Sheeeeeesh!" << endl;
        }

    private:
        const string type_;
};

class Cat : public Animal {
    public:
        Cat() : Animal("Cat") {}

        void Sound() const override {
            cout << "Meow!" << endl;
        }
};

class Dog : public Animal {
    public:
        Dog() : Animal("Dog") {}

        void Sound() const override {
            cout << "Whaf!" << endl;
        }
};

class Parrot : public Animal {
    public:
        Parrot(const string& name) : Animal("Parrot"), name_(name) {}

        void Sound() const override {
            cout << name_ << " is good!" << endl;
        }

    private:
        const string& name_;
};

class Horse : public Animal {
    public:
        Horse() : Animal("Horse") {}
};

void MakeSound(const Animal& a) {
    a.Sound();
}

int main() {
    Cat c;
    Dog d;

    Horse h;

    Parrot p("Kesha");


    MakeSound(c);
    MakeSound(d);
    MakeSound(p);
    MakeSound(h);

    return 0;
}
