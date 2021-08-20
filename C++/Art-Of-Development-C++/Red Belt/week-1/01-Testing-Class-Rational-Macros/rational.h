#pragma once
#include "headers.h"

class Rational {
    public:
        Rational() = default;
        Rational(int nn, int dd);

        int Numerator() const;
        int Denominator() const;

    private:
        int n = 0;
        int d = 1;
};
