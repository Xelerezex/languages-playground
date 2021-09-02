// DOESN'T COMPILE OR GET WARNING:

// I compiled it that way: gcc -std=c17 -Wall -Werror 0-exmpl-hello-world.c && ./a.out
#include <stdio.h>

int main() {
    printf("Hello, word?\n\z");
} //                      ^
  //                      | Cause of -Werror Programm falls here
