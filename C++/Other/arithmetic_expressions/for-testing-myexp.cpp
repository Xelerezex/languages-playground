#include <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

class Operation {
    public:
        Operation(const char& op) : operation(op) {}

        int Evaluate() const {
            if (operation == '+') {
                return left + right;
            } else {
                return 0;
            }
        }

        void SetLeft(const int& l) {
            left = l;
        }

        void SetRight(const int& r) {
            right = r;
        }

    private:
        const char operation;
        int left, right;
};

int main() {
    Operation op('+');
    op.SetLeft(1);
    op.SetRight(2);
    int res = op.Evaluate();

    cout << res << endl;

    return 0;
}
