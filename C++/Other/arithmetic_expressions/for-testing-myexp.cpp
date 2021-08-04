#include <iostream>
#include <string>
#include <vector>


#include "container_cout.h"


using namespace std;

int makeOperation(int& left, int& right, char& oper) {
    if (oper == '+') {
        return left + right;
    } else if (oper == '-') {
        return left - right;
    }
    return 0;
}

int main() {

    string token = "1+2+3+4+5+0+9";

    stack<int> numbers;
    stack<char> operations;


    for (const auto& item : token) {
        if (item >= '0' or '9' <= item) {
            int z = item - '0';
            numbers.push(static_cast<int>(z));
        } else if (item == '+' || item == '-') {
            operations.push(item);
        }
    }





    cout << "numbers stack     :  " <<  numbers     << endl;
    cout << "operations stack  :  " <<  operations  << endl;

    return 0;
}
