#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;


class VarOne {
public:
    VarOne(const int& var) {
        if (var == 42) {
            Value = 84;
        }
    }

    int value() const {
        return Value;
    }

private:
    int Value;
};


class VarTwo {
public:
    VarTwo (const int& var) : Value( [var] {
                                        if (var == 42) {
                                            return 42 * 2;
                                        } else {
                                            return 0;
                                        }
                                    } ()) {}

    int value() const {
        return Value;
    }

private:
    int Value;
};

class VarThree {
public:
    VarThree (char var) : Value(var - '0') {}

    int value() const {
        return Value;
    }

private:
    int Value;
};

int main() {
    VarOne one(42);
    cout << one.value() << endl;


    cout << "--------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------------------------------//


    VarTwo two(42);
    cout << two.value() << endl;


    cout << "--------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------------------------------//


    // (int)'9' = 57, (int)('9' - '0') = 9, bcs code_of_number - code_of_number

    char digit = '9';
    cout << static_cast<int>(digit) << endl;
    cout << static_cast<int>(digit - '0') << endl;


    cout << "--------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------------------------------//


    VarThree three('7');
    cout << three.value() << endl;


    cout << "--------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------------------------------//


    const string& STR = "LOL!", ANOTHER1 = "FUCK", ANOTHER2 = "42", ANOTHER3 = "AGAIN";

/*
    auto lambda_function = [&ANOTHER1, &ANOTHER2, &ANOTHER3](const string& str, const int G = 42){
        cout << str << " " << G << endl;
        cout << ANOTHER1 << " " << ANOTHER2 << " " << ANOTHER3 << endl;
    };
*/

    // EQUIVALENT:

    auto lambda_function = [&](const string& str, const int G = 42){
        cout << str << " " << G << endl;
        cout << ANOTHER1 << " " << ANOTHER2 << " " << ANOTHER3 << endl;
    };
    lambda_function(STR);


    cout << "--------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------------------------------//

}
