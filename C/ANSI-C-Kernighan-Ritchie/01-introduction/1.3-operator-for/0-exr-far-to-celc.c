#include <stdio.h>

int main() {
    for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.00) * (fahr - 32));
    }
}
