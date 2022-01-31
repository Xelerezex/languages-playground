// Rule #17
// If smart ptr allocated with new, better to write it in next sentence

#include "tools.h"

class Widget
{};

void processWidget(std::shared_ptr<Widget> pw, int priority)
{}

int priority()
{
    return 0;
}

int main()
{
    {       // Do not do that:
        processWidget(std::shared_ptr<Widget>(new Widget), priority());
    }
    {       // Do that:
        std::shared_ptr<Widget> pw(new Widget);

        processWidget(pw, priority());
    }
}
