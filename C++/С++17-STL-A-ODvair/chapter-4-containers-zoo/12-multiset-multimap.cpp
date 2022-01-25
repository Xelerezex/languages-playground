#include "tools.h"

int main()
{
    {
        std::multimap<std::string, std::string> mm;
        mm.emplace("hello", "world");
        mm.emplace("quick", "brown");
        mm.emplace("hello", "dolly");
        ASSERT(mm.size() == 3);

        auto it = mm.begin();
        using Pair = decltype(mm)::value_type;
        ASSERT(*(it++) == Pair("hello", "world"));
        ASSERT(*(it++) == Pair("hello", "dolly"));
        ASSERT(*(it++) == Pair("quick", "brown"));
    }
    {
        std::multimap<std::string, std::string> mm {
            {"hello", "world"},
            {"quick", "brown"},
            {"hello", "dolly"}
        };

        ASSERT(mm.count("hello") == 2);
        mm.erase("hello");
        ASSERT(mm.count("hello") == 0);
    }
}
