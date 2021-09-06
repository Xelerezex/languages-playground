#include <stdio.h>

int main() {
    int c;

    // PRIORITET OF != MORE THAN = BCS OF THAT BRACES - ALWAYS SHOULD BE
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
