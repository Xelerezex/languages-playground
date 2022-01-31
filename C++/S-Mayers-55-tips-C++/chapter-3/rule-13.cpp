// Rule #13
// Use objects for resource managment
#include "tools.h"

class Investment {};

Investment* createInvestment()
{
    Investment *out = new Investment();
    return out;
}

/* Wrong way to clear resource
* void some_f()
* {
*     Investment *pInv = createInvestment();
*
*     delete pInv;
* }
*/

void some_f()
{
    std::shared_ptr<Investment> pInv1(createInvestment());
    std::shared_ptr<Investment> pInv2(createInvestment());

    pInv1 = pInv2;
}

int main()
{
    some_f();
}
