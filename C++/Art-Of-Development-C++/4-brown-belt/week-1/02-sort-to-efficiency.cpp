#include "tools.h"

int main()
{
    std::unordered_map<std::string, int> freqs;

    {
        LOG_DURATION("FILL:")
        std::fstream fs("input.txt");
        std::string text;
        while (fs >> text)
        {
            ++freqs[text];
        }
    }

    for (const auto &[key, count] : Head(freqs, 7))
    {
        std::cerr << key << " : " << count << std::endl;
    }
    std::cerr << "-------------------------------------------" << std::endl;

    LOG_DURATION("Copy and Sort");
    std::vector<std::pair<std::string, int>> words (freqs.begin(), freqs.end());
    std::sort(
        words.begin(),
        words.end(),
        [] (const auto& l, const auto& r) {
            return l.second > r.second;
        }
    );

    for (const auto &[key, count] : Head(words, 7))
    {
        std::cerr << key << " : " << count << std::endl;
    }

    return 0;
}
