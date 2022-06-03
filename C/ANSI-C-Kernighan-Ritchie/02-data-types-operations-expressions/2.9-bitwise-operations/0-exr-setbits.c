#include <stdint.h>
#include "printbin.h"

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    // return x | ((y << p) & ~(~0 << (p + n)));
    return (x | ((~(~0 << n) & y) << (p + 1 - n)));
}

int main()
{
    // printfb(6969, 16);
    printfb(setbits(0, 3, 3, 32767), 16);
    // printfb(setbits(32767, 3, 3, 0), 16);
    printfb(setbits(0b0000000, 3, 3, 0b11111101), 16);

}
