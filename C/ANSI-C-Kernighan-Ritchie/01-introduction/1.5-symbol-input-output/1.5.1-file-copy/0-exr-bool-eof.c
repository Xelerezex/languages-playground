#include <stdio.h>

#define TRUE 1

int main() {
    int character;

    while ((character = getchar()) != EOF) {
        int type = (getchar() != EOF);
        printf("%d\n", type);               // UNIX: CTRL+D <- EOF KEYBORD
    }
}
