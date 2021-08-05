#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <iomanip>


using namespace std;


enum class TokenType {
    DATE,
    EVENT,
    COLUMN,
    LOGICAL_OP,
    COMPARE_OP,
    PAREN_LEFT,
    PAREN_RIGHT,
};

struct Token {
    const string value;
    const TokenType type;
};


vector<Token> Tokenize(istream& cl) {
    vector<Token> tokens;

    char c;
    while (cl >> c) {
        if (isdigit(c)) {
            string date(1, c);
            for (int i = 0; i < 3; ++i) {
                while (isdigit(cl.peek())) {
                    date += cl.get();
                }
                if (i < 2) {
                    date += cl.get(); // Consume '-'
                }
            }
            tokens.push_back({date, TokenType::DATE});
        } else if (c == '"') {
            string event;
            getline(cl, event, '"');
            tokens.push_back({event, TokenType::EVENT});
        } else if (c == 'd') {
            if (cl.get() == 'a' && cl.get() == 't' && cl.get() == 'e') {
                tokens.push_back({"date", TokenType::COLUMN});
            } else {
                throw logic_error("Unknown token");
            }
        } else if (c == 'e') {
            if (cl.get() == 'v' && cl.get() == 'e' && cl.get() == 'n' &&
                    cl.get() == 't') {
                tokens.push_back({"event", TokenType::COLUMN});
            } else {
                throw logic_error("Unknown token");
            }
        } else if (c == 'A') {
            if (cl.get() == 'N' && cl.get() == 'D') {
                tokens.push_back({"AND", TokenType::LOGICAL_OP});
            } else {
                throw logic_error("Unknown token");
            }
        } else if (c == 'O') {
            if (cl.get() == 'R') {
                tokens.push_back({"OR", TokenType::LOGICAL_OP});
            } else {
                throw logic_error("Unknown token");
            }
        } else if (c == '(') {
            tokens.push_back({"(", TokenType::PAREN_LEFT});
        } else if (c == ')') {
            tokens.push_back({")", TokenType::PAREN_RIGHT});
        } else if (c == '<') {
            if (cl.peek() == '=') {
                cl.get();
                tokens.push_back({"<=", TokenType::COMPARE_OP});
            } else {
                tokens.push_back({"<", TokenType::COMPARE_OP});
            }
        } else if (c == '>') {
            if (cl.peek() == '=') {
                cl.get();
                tokens.push_back({">=", TokenType::COMPARE_OP});
            } else {
                tokens.push_back({">", TokenType::COMPARE_OP});
            }
        } else if (c == '=') {
            if (cl.get() == '=') {
                tokens.push_back({"==", TokenType::COMPARE_OP});
            } else {
                throw logic_error("Unknown token");
            }
        } else if (c == '!') {
            if (cl.get() == '=') {
                tokens.push_back({"!=", TokenType::COMPARE_OP});
            } else {
                throw logic_error("Unknown token");
            }
        }
    }

    return tokens;
}


ostream& operator<<(ostream& os, vector<Token> VT) {
    for (const auto& pair : VT) {

        switch (pair.type) {
            case TokenType::DATE:
                os << setfill(' ') << setw(15) << left << pair.value << ":" << setfill(' ') << setw(25) << right <<  "TokenType::DATE" << endl;
                break;
            case TokenType::EVENT:
                cout << setfill(' ') << setw(15) << left << pair.value << ":" << setfill(' ') << setw(25) << right <<  "TokenType::EVENT" << endl;
                break;
            case TokenType::COLUMN:
                cout << setfill(' ') << setw(15) << left << pair.value << ":" << setfill(' ') << setw(25) << right <<  "TokenType::COLUMN" << endl;
                break;
            case TokenType::LOGICAL_OP:
                cout << setfill(' ') << setw(15) << left << pair.value << ":" << setfill(' ') << setw(25)  << right << "TokenType::LOGICAL_OP" << endl;
                break;
            case TokenType::COMPARE_OP:
                cout << setfill(' ') << setw(15) << left << pair.value << ":" << setfill(' ') << setw(25) << right <<  "TokenType::COMPARE_OP" << endl;
                break;
            case TokenType::PAREN_LEFT:
                cout << setfill(' ') << setw(15) << left << pair.value << ":" << setfill(' ') << setw(25) << right <<  "TokenType::PAREN_LEFT" << endl;
                break;
            case TokenType::PAREN_RIGHT:
                cout << setfill(' ') << setw(15) << left << pair.value << ":" << setfill(' ') << setw(25) << right <<  "TokenType::PAREN_RIGHT" << endl;
                break;
        }
    }
    return os;
}

int main() {
    stringstream is0("date < 2017-11-06");
    auto tokens0 = Tokenize(is0);
    cout << tokens0 << endl << "---------------------------------------------------------------\n";


    stringstream is1("event != \"holiday\"");
    auto tokens1 = Tokenize(is1);
    cout << tokens1 << endl << "---------------------------------------------------------------\n";


    stringstream is2("date >= 2017-01-01 AND date < 2017-07-01 AND event == \"sport event\"");
    auto tokens2 = Tokenize(is2);
    cout << tokens2 << endl << "---------------------------------------------------------------\n";


    stringstream is3("date < 2017-01-01 AND (event == \"holiday\" OR event == \"sport event\")");
    auto tokens3 = Tokenize(is3);
    cout << tokens3 << endl << "---------------------------------------------------------------\n";
    return 0;
}
