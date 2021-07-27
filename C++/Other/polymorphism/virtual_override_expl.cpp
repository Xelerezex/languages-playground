#include <iostream>

using namespace std;

class Weapon {
    public:
        virtual void Shoot() = 0;
};

class Gun : public Weapon {
    public:
        void Shoot() override {
            cout << "PAU!" << endl;
        }
};

class SubMachineGun : public Weapon {
    public:
        void Shoot() override {
            cout << "PAU PAU PAU!!!";
        }
};

class Player {
    public:
        void Shoot(Weapon *weapon) {
            weapon -> Shoot();
        }
};

int main() {

    Gun gun;
    SubMachineGun machinegun;

    Player player;
    player.Shoot(&gun);

    return 0;
}
