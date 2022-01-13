// Rule #10
// Assignments operators should return reference to *this

class Widget
{
    public:
        Widget& operator+=(const Widget& rhs)
        {
            return *this;
        }

        Widget& operator=(const Widget& rhs)
        {
            return *this;
        }
};

int main()
{
    int x, y, z;
    x = y = z = 15;     // (x = (y = (z = 15)))
}
