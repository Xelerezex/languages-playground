#include <stdint.h>
#include "printbin.h"

unsigned invert(unsigned x, unsigned p, unsigned n)
{
    return (x ^ (~(~0 << n) << (p + 1 - n)));
}

int main()
{

    printfb(invert(0b0000000000000000, 3, 3), 16);
    printfb(invert(0b0000000000001110, 3, 3), 16);

}
