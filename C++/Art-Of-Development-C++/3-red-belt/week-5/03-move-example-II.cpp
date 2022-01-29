#include "profile.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<string> SplitIntoWords(const string& text) {
    vector<string>  words;
    string current_word;
    for (const char c : text) {
        if (c == ' ') {
            words.push_back(move(current_word));
            current_word.clear();
        } else {
            current_word.push_back(c);
        }
    }


    words.push_back(current_word);
    return words;
}

int main() {
    {
        LOG_DURATION("without move");

        for (const string& word : SplitIntoWords("Red belt C++")) {
            cout << word << "\n";
        }
    }
    return 0;
}
