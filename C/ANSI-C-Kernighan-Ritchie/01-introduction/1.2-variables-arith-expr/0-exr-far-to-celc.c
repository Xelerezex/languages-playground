#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("---------------------------\n");
    printf("| Fahrengheit  |  Celsius |\n");
    printf("+--------------+----------+\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("| %8.0f\t   | %8.3f |\n", fahr, celsius);
        printf("+--------------+----------+\n");
        fahr = fahr + step;
    }
}
