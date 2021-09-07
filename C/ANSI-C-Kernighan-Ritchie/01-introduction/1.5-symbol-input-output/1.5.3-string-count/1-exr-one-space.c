#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main() {
    char c;
    int flag = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            flag = TRUE;
        } else {
            if (flag == TRUE) {
                putchar(' ');
            }
            putchar(c);
            flag = FALSE;
        }
    }
}
