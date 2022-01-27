#include "tools.h"
#include <string.h>

char * bad_greet(const char *name)
{
    char buffer[100];
    snprintf(buffer, 100, "hello %s", name);
    return strdup(buffer);
}

std::string greet(const std::string &name)
{
    return "hello " + name;
}

int main()
{
    {
        const char *who = "world";
        char *hw = bad_greet(who);
        ASSERT(strcmp(hw, "hello world") == 0);
        free(hw);
    }
    {
        std::string who = "world";
        ASSERT(greet(who) == "hello world");
    }
}
