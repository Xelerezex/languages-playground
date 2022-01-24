// Rule #15
// All give access to resourses from manager-classes

#include "tools.h"

class Investment {
    public:
        bool isTaxFree()
        {
            return true;
        }
};

Investment* createInvestment()
{
    Investment *out = new Investment();
    return out;
}

int daysHeld(const Investment *pi)
{
    return 9;
}

int main()
{
    std::shared_ptr<Investment> pInv1(createInvestment());
    std::shared_ptr<Investment> pInv2(createInvestment());
    // First way:
    // int days = daysHeld(pInv1.get());
    // Second way
    bool taxable1 = !(pInv1->isTaxFree());
    bool taxable2 = !((*pInv2).isTaxFree());
}
