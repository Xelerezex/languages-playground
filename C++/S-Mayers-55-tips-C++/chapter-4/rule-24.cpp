// Rule #24
// declare non-member functions when type conversion should be applicable to all parameters

class Rational
{
    public:
        Rational(int numerator = 0, int denominator = 1) : num(numerator), den(denominator)
        {}

        int numerator() const
        {
            return num;
        }

        int denominator() const
        {
            return den;
        }
    private:
        int num, den;
};

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

int main()
{
    Rational oneFourth(1, 4);
    Rational result;

    result = oneFourth * 2;
    result = 2 * oneFourth;
}
