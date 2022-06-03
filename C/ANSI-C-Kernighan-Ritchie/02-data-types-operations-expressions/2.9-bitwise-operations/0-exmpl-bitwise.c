#include <stdint.h>
#include "printbin.h"


unsigned getbits(unsigned x, int p, int n)
{
    printfb((p + 1 - n), 16);
    printfb((x >> (p + 1 - n)), 16);
    printfb((~0 << n), 16);
    printfb(~(~0 << n), 16);
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
    /* --- example one starts --- */
    printf("Example one:\n");
    int32_t valueA = 0b11111111111111111111111111111111;
    int32_t valueX = 127;
    printfb(valueA, 32);

    valueX = valueA & 0177;     // ValueA (binary) & 0177 (octal)

    printfb(0177, 32);
    printfb(valueX, 32);
    printf("\n");
    /* --- example one stops --- */

    /* --- example two starts --- */
    printf("Example two:\n");
    valueA = 0b0000000000000000;
    valueX = 0b1001001001001001;
    printfb(valueA, 16);
    printfb(valueX, 16);

    valueX = valueA | 0b1001001001001001;

    printfb(valueX, 16);
    printf("\n");
    /* --- example two stops --- */

    /* --- example three starts --- */
    printf("Example three:\n");
    valueA = 0b1111111111111111;
    valueX = 0b0000000000000000;
    printfb(valueA, 16);
    printfb(valueX, 16);

    valueX = valueA ^ 0b1001001001001001;

    printfb(valueX, 16);
    printf("\n");
    /* --- example three stops --- */

    /* --- example four starts --- */
    printf("Example four:\n");
    valueA = 0b0000001111000000;
    printfb(valueA, 16);
    printf("%d\n", valueA);

    valueA = valueA << 4;   // Equivalent of 960 (dec of valueA) * 16 [1^2, 2^2, 3^2, 4^2, 5^2, ...]
    printf("%d\n", valueA);

    printfb(valueA, 16);
    printf("\n");
    /* --- example four stops --- */

    /* --- example five starts --- */
    printf("Example five:\n");
    valueA = 0b1111000000000000;
    printfb(valueA, 16);

    valueX = valueA >> 3;

    printfb(valueX, 16);
    printf("\n");
    /* --- example five stops --- */

    /* --- example six starts --- */
    printf("Example six:\n");
    printf("077: %d\n", 077);
    printf("~077: %d\n", ~077);

    valueA = 0b0000000001111111;
    printfb(valueA, 16);
    printfb(-64, 16);

    valueX = valueA & ~077;

    printfb(valueX, 16);
    printf("\n");
    /* --- example six stops --- */

    /* --- example six starts --- */
    printfb(0b00011100 >> 0b00000011, 16);
    printfb(getbits(0b00001111, 5, 4), 16);
    /* --- example six stops --- */

    return 0;
}
