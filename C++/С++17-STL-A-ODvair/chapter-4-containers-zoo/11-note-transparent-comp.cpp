#include "tools.h"

struct MagicLess
{
    using is_transparent = std::true_type;

    template<class T, class U>
    bool operator()(T&& t, U&& u) const
    {
        return std::forward<T>(t) < std::forward<U>(u);
    }
};

int main()
{
    {
        std::map<std::string, std::string, MagicLess> m;

        std::map<std::string, std::string, std::less<>> m2;

        auto it = m2.find("hello");
    }
    {
        auto [begin, end] = m.equal_range("hello");
        m.erase(begin, end);
    }
}
