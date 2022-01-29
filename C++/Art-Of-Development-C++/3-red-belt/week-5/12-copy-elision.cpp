#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Logger {
    public:
        Logger() { cout << "Default ctor\n"; }
        Logger(const Logger&) { cout << "Copy ctor\n"; }
        Logger(Logger&&) { cout << "Move ctor\n"; }
};

Logger MakeLogger() {
    return Logger();
}

int main() {
    Logger logger = MakeLogger();

    return 0;
}
