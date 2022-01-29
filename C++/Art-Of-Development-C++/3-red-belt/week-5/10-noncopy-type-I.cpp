#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Logger {
    public:
        Logger() { cout << "Default ctor\n"; }
        Logger(const Logger&) = delete; // { cout << "Copy ctor\n"; }
        Logger(Logger&&) { cout << "Move ctor\n"; }
};

int main() {
    Logger other_logger;
    Logger logger = move(other_logger);

    return 0;
}
