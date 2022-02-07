#include "tools.h"

int main()
{
    std::set<std::string> s_words;

    std::fstream fs("input.txt");

    std::string text;
    while (fs >> text)
    {
        s_words.insert(text);
    }

    for (const auto &s : Head(s_words, 7))
    {
        std::cerr << s << std::endl;
    }
    std::cerr << "-------------------------------------------" << std::endl;

    {
        LOG_DURATION("set::lower_bound method");
        for (char c = 'a'; c < 'z'; ++c)
        {
            std::string s(1, c);
            s_words.lower_bound(s);
        }
    }

    {
        LOG_DURATION("global lower_bound in set");
        for (char c = 'a'; c < 'z'; ++c)
        {
            std::string s(1, c);
            lower_bound(begin(s_words), end(s_words), s);
        }
    }
    return 0;
}
