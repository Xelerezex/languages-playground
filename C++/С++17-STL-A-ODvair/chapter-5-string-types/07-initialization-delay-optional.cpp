#include "tools.h"

std::map<std::string, int> g_limits = {
    { "memory", 655360 }
};

std::variant<std::monostate, int>
get_resourse_limit(const std::string& key)
{
    if (auto it = g_limits.find(key); it != g_limits.end())
    {
        return it -> second;
    }
    return std::monostate{};
}


int main()
{
    {
        auto limit = get_resourse_limit("memory");
        if (std::holds_alternative<int>(limit))
        {
            use( std::get<int>(limit) );
        }
        else
        {
            use( some_default );
        }
    }
}
