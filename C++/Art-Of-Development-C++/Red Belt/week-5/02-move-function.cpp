#include "profile.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<string> ReadStrings(istream& stream, bool use_move) {
    vector<string> strings;
    string s;
    while (stream >> s) {
        if (use_move) {
            strings.push_back(move(s));
        } else {
            strings.push_back(s);
        }
    }
    return strings;
}

string GenerateText() {
    const int SIZE = 300'000'000;
    const int WORD_LENGTH = 300'000'000;
    string text(SIZE, 'a');
    for (int i = WORD_LENGTH; i < SIZE; i += WORD_LENGTH) {
        text[i] = ' ';
    }
    return text;
}

int main() {
    const string text = GenerateText();

    {
        LOG_DURATION("without move");
        istringstream stream(text);
        ReadStrings(stream, false);
    }
    {
        LOG_DURATION("with move");
        istringstream stream(text);
        ReadStrings(stream, true);
    }

    return 0;
}
