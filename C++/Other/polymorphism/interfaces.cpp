#include <iostream>

class IBicycle { // I --> for interface
    public:
        void virtual TwistTheWeel() = 0;
        void virtual Ride() = 0;
};

class SimpleBike : public IBicycle {
    public:
        void TwistTheWeel() override {
            std::cout << "SimpleBike sb.TwistTheWeel()" << std::endl;
        }
        void Ride() override {
            std::cout << "SimpleBike sb.Ride()" << std::endl;
        }
};

class SportBike : public IBicycle {
    public:
        void TwistTheWeel() override {
            std::cout << "SportBike sb.TwistTheWeel()" << std::endl;
        }
        void Ride() override {
            std::cout << "SportBike sb.Ride()" << std::endl;
        }
};

class Person {
    public:
        void RideOn(IBicycle& bike) {
            // std::cout << "Twisting" << std::endl;
            bike.TwistTheWeel();
            // std::cout << "Go!" << std::endl;
        }
};

int main() {
    SimpleBike sb;
    SportBike spb;

    Person p;

    p.RideOn(sb);
    p.RideOn(spb);

    return 0;
}
