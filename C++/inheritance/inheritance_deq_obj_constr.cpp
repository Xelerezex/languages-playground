#include <iostream>

using namespace std;

struct Log {
    Log(string name) : n(name) {
        cout << "+ " << n << endl;
    }

    ~Log() {
        cout << "- " << n << endl;
    }

    string n;
};

struct Fruit {
    Fruit(const string& t)
        : l(t + " (Fruit)"){ // Analog: const string type = "fruit";

    }

    const Log l;
};

struct Apple : public Fruit {
    Apple(const string& t) : Fruit(t), l("Apple") { // Analog: type = "Apple";
    }

    const Log l;
};

class AppleTree {
    public:
        AppleTree()
            : a1("a1"),
              a2("a2") {
        }

        Log l = Log("AppleTree");
        Apple a1;
        Apple a2;
};

int main() {
    AppleTree at;

    return 0;
}
