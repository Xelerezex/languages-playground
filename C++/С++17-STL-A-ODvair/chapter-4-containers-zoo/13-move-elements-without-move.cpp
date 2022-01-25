#include "tools.h"

int main()
{
    {
        std::map<std::string, std::string> m
        {
            {"hello", "world"},
            {"quick", "brown"},
        };

        std::map<std::string, std::string> otherm
        {
            {"hello", "dolly"},
            {"sad", "clown"},
        };

        m.merge(otherm);

        ASSERT((
            otherm == decltype(m) {
                {"hello", "dolly"},
            }
        ));

        ASSERT((
            m == decltype(m) {
                {"hello", "world"},
                {"quick", "brown"},
                {"sad", "clown"},
            }
        ));
    }
    {
        std::map<std::string, std::string> m
        {
            {"hello", "world"},
            {"quick", "brown"},
        };

        std::map<std::string, std::string> otherm
        {
            {"hello", "dolly"},
            {"sad", "clown"},
        };

        using Pair = decltype(m)::value_type;

        auto nh1 = otherm.extract("sad");
        ASSERT(nh1.key() == "sad" && nh1.mapped() == "clown");
        auto [it2, inserted2, nh2] = m.insert(std::move(nh1));
        ASSERT(*it2 == Pair("sad", "clown") && inserted2 == true && nh2.empty());

        auto nh3 = otherm.extract("hello");
        ASSERT(nh3.key() == "hello" && nh3.mapped() == "dolly");
        auto [it4, inserted4, nh4] = m.insert(std::move(nh3));
        ASSERT(*it4 == Pair("hello", "world") && inserted4 == false && !nh4.empty());

        m.insert_or_assign(nh4.key(), nh4.mapped());

        m.erase(it4);
        m.insert(std::move(nh4));
    }
    {
        std::map<std::string, std::string> m
        {
            {"hello", "world"},
            {"quick", "brown"},
        };

        ASSERT(m.begin()->first == "hello");
        ASSERT(std::next(m.begin())->first == "quick");

        auto nh = m.extract("quick");
        std::transform(nh.key().begin(), nh.key().end(), nh.key().begin(), ::toupper);
        m.insert(std::move(nh));

        ASSERT(m.begin()->first == "QUICK");
        ASSERT(std::next(m.begin())->first == "hello");
    }
}
