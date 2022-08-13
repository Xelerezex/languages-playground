#include <stdint.h>
#include "printbin.h"

unsigned char rightrot(unsigned char x, unsigned n)
{
    while (n-- != 0)
    {
        if (x & 1)
        {
            x = (x >> 1) | ~(~0 >> 1);
        }
        else
        {
            x = x >> 1;
        }
    }
    return x;
}

int main()
{
    printfb(0xFF, 8);
    printfb(rightrot(0xFF, 1), 8);
    printfb(rightrot(0xFF, 3), 8);

}
