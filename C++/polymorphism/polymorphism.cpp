#include <iostream>

using namespace std;

class Animal {
    public:
        Animal(const string& type = "animal") : type_(type) {
        }

        void Eat(const string str) {
            cout << type_ << " eats " << str << ". " << endl;
        }

        void Voice() const {
            if (type_ == "Cat") {
                cout << "Meow!" << endl;
            } else if (type_ == "Dog") {
                cout << "Whaf!" << endl;
            } else if (type_ == "Parrot") {
                cout << name_ << " is good!" << endl;
            }
        }

    private:
        const string type_;
};

class Cat : public Animal {
    public:
        Cat() : Animal("Cat") {}
};

class Dog : public Animal {
    public:
        Dog() : Animal("Dog") {}
};

class Parrot : public Animal {
    public:
        Parrot(const string& name) : Animal("Parrot"), name_(name) {}

        void Talk() {
            cout << name_ << " is good!" << endl;
        }

    private:
        const string& name_
};

void MakeSound(const Animal& a) {
    a.Voice();
}

int main() {
    Cat c;
    Dog d;

    c.Eat("apple");
    d.Eat("orange");

    MakeSound(c);
    MakeSound(d);

    return 0;
}
