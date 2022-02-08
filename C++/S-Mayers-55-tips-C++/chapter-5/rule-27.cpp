// Rule #27
// Don't overuse type casting

#include "tools.h"

class Base {};
class Derived : public Base {};

class Window {};

class SpecialWindow
{
    public:
        void blink() {}

};

using VPW = std::vector<std::shared_ptr<Window>>;

VPW winPtrs;

int main()
{
    {
        int x, y;

        double d = static_cast<double>(x) / y;
    }
    {
        Derived d;
        Base *pb = &d;
    }
    {
        for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
        {
            if (SpecialWindow psw = dynamic_cast<SpecialWindow>(iter->get()))
            {
                psw.blink();
            }
        }
    }
}
