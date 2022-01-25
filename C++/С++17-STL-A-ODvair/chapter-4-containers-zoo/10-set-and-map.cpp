#include "tools.h"

int main()
{
    {
        std::set<int> s;
        for (int i : {3, 1, 4, 1, 5})
        {
            s.insert(i);
        }

        ASSERT((s == std::set{1, 3, 4, 5}));

        auto it = s.begin();
        ASSERT(*it == 1);
        s.erase(4);
        s.erase(it);

        ASSERT((s == std::set{3, 5}));
    }
    {
        std::set<int> s;
        auto [it1, b1] = s.insert(1);
        ASSERT(*it1 == 1 && b1 == true);

        auto [it2, b2] = s.insert(2);
        ASSERT(*it2 == 2 && b2 == true);

        auto [it3, b3] = s.insert(1);
        ASSERT(*it3 == 1 && b3 == false);
    }
    {
        std::map<std::string, std::string> m;
        m["hello"] = "world";
        m["quick"] = "brown";
        m["hello"] = "dolly";

        ASSERT(m.size() == 2);

        ASSERT(m["literally"] == "");
        ASSERT(m.size() == 3);

        using Pair = decltype(m)::value_type;

        if (m.find("hello") == m.end())
        {
            m.insert(Pair{"hello", "dolly"});
            m.emplace("hello", "dolly");
        }
    }
}
