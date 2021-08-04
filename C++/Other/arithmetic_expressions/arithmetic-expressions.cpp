#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

#include "container_cout.h"
// Внимание!
// Для простоты разбора будем использовать только числа из одной цифры,
// а также не будет скобок, пробелов и ненужных символов.
// При этом, будем считать, что выражение всегда корректно.

struct Node {
    public:
        virtual int Evaluate() const = 0;
        virtual int Get() const = 0;
};


struct Value : public Node {
    public:
        Value(char digit) : _value(digit - '0') {}

        int Evaluate() const override { return _value; }

        int Get() const override { return _value; }

    private:
        const uint8_t _value;
};


struct Variable : public Node {
    public:
        Variable(const int &x) : _x(x) {}

        int Evaluate() const override { return _x; }

        int Get() const override { return _x; }

    private:
        const int &_x;
};


struct Op : public Node {
    Op(char value) : precedence( [value] {
            if (value == '*') {
                    return 2;
                } else {
                    return 1;
                }
        } ()),
    _op(value) {}

    const uint8_t precedence;      // Priority

    int Evaluate() const override {
        if (_op == '*') {
            return _left->Evaluate() * _right->Evaluate();
        } else if (_op == '+') {
            return _left->Evaluate() + _right->Evaluate();
        } else if (_op == '-') {
            return _left->Evaluate() - _right->Evaluate();
        }

        return 0;
    }

    int Get() const override { return _op; }

    void SetLeft(shared_ptr<Node> node) {
        _left = node;
    }
    void SetRight(shared_ptr<Node> node) {
        _right = node;
    }


private:
    const char _op;
    shared_ptr<const Node> _left, _right;
};


template <class Iterator>
shared_ptr<Node> Parse(Iterator token, Iterator end, const int &x) {
    // Empty expression
    if (token == end) {
        return make_shared<Value>('0');
    }

    stack<shared_ptr<Node>> values;
    stack<shared_ptr<Op>> ops;

    auto PopOps = [&](int precedence)  {

    while (!ops.empty() && ops.top()->precedence >= precedence) {


        cout << "stack change 1.1: " << values << endl;
        auto value1 = values.top();
        values.pop();
        cout << "stack change 1.2: " << values << endl << endl;


        cout << "stack change 2.1: " << values << endl;
        auto value2 = values.top();
        values.pop();
        cout << "stack change 2.1: " << values << endl << endl;


        cout << "stack change 3.1: " << ops << endl;
        auto op = ops.top();
        ops.pop();
        cout << "stack change 3.2: " << ops << endl << "----------------------------------------" << endl;


        op->SetRight(value1);
        op->SetLeft(value2);


        values.push(op);
        }
    };


    while (token != end) {
        const auto &value = *token;
        cout << "(val)\t: " << value << endl;


        if (value >= '0' && value <= '9') {
            values.push(make_shared<Value>(value));
        } else if (value == 'x') {
            values.push(make_shared<Variable>(x));
        } else if (value == '*') {
            PopOps(2);
            ops.push(make_shared<Op>(value));
        } else if (value == '+' || value == '-') {
            PopOps(1);
            ops.push(make_shared<Op>(value));
        }


        ++token;
    }

    while (!ops.empty()) {
        PopOps(0);
    }

    return values.top();
}

int main() {
    string tokens;
    cout << "Enter expression: \n";
    //getline(cin, tokens);
    tokens = "1+2";

    int x = 0;
    auto node = Parse(tokens.begin(), tokens.end(), x);

    //cout << "Expression value: " << node->Evaluate() << endl;

    /*cout << "Enter x: ";
    while (cin >> x) {
        cout << "Expression value: " << node->Evaluate() << endl;
        cout << "Enter x: ";
    }*/

    return 0;
}
