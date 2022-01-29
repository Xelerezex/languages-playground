#include "rational.h"

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

Rational::Rational(int nn, int dd) {
    int g = gcd(nn, dd);
    n = nn / g;
    d = dd / g;
    if (d < 0) {
        d = -d;
        n = -n;
    }
}

int Rational::Numerator() const {
    return n;
}
int Rational::Denominator() const {
    return d;
}

