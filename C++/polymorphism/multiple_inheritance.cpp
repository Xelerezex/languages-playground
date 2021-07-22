#include <iostream>


using namespace std;


class Car {
    public:
        Car(const string type  = "Car" ) : type_(type) {}

        virtual void Drive() {
            cout << type_ << " Drive." << endl;
        }

    private:
        const string type_;
};


class AirPlain {
    public:
        AirPlain(const string type  = "Airplain") : type_(type) {}

        virtual void Fly() {
            cout << type_ << " Fly." << endl;
        }

    private:
        const string type_;
};


class AirCar : public Car, public AirPlain {
    public:
        AirCar(const string type  = "AirCar") : type_(type) {}

/*        void Drive() override {
            cout << type_ << " Drive." << endl;
        }

        void Fly() override {
            cout << type_ << " Fly." << endl;
        }*/

    private:
        const string type_;
};

int main(){
    Car car;
    car.Drive();


    AirPlain airplain;
    airplain.Fly();


    AirCar aircar;
    aircar.Drive();
    aircar.Fly();


    return 0;
}
