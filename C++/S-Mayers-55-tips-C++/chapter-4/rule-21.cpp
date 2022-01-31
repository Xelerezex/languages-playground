// Rule #21
// Do not return a reference when you should return object.




class Rational
{
    public:
        Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator)
        {}

        int GetN() const
        {
            return n;
        }

        int GetD() const
        {
            return d;
        }

    private:
        int n, d;
        friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational{lhs.GetN() * rhs.GetN(), lhs.GetD() * rhs.GetD()};
}

int main()
{
    Rational a(1, 2);
    Rational b(3, 5);

    Rational c = a * b;
}
