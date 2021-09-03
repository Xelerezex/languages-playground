#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 5;

    celsius = lower;

    printf("---------------------------\n");
    printf("| Celsius  | Fahrengheit  |\n");
    printf("+----------+--------------+\n");
    while (celsius <= upper) {
        fahr = (celsius * (9.0 / 5.0)) + 32.0;
        printf("|%8.0f  |    %8.3f  |\n", celsius, fahr);
        printf("+----------+--------------+\n");
        celsius = celsius + step;
    }
}
