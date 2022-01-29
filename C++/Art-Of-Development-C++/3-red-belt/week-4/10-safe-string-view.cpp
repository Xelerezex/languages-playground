#include "test_runner.h"
#include "profile.h"

vector<string> SplitIntoWords(const string& str) {
    vector<string> result;

    auto str_begin = begin(str);
    const auto str_end = end(str);

    while (true) {
        auto it = find(str_begin, str_end, ' ');

        result.push_back(string(str_begin, it));

        if (it == str_end) {
            break;
        } else {
            str_begin = it + 1;
        }
    }

    return result;
}

vector<string_view> SplitIntoWordsStrView(string_view str) {
    vector<string_view> result;

    size_t pos = 0;
    const size_t pos_end = str.npos;

    while (true) {
        size_t space = str.find(' ', pos);

        result.push_back(
            space == pos_end
            ? str.substr(pos)
            : str.substr(pos, space - pos)
        );

        if (space == pos_end) {
            break;
        } else {
            pos = space + 1;
        }
    }

    return result;
}

string GenerateText() {
    const int SIZE = 10'000'000;
    string text(SIZE, 'a');
    for (int i = 100; i < SIZE; i += 100) {
        text[i] = ' ';
    }
    return text;
}

int main() {
    const string text = GenerateText();
    {
        LOG_DURATION("string");
        const auto words = SplitIntoWords(text);
        // cout << words[0] << '\n';
    }
    {
        LOG_DURATION("string_view");
        const auto words = SplitIntoWordsStrView(text);
        // cout << words[0] << '\n';
    }


}
