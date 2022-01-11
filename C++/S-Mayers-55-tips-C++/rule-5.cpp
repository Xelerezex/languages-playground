// Rule #5
// classes could quitely generate constructors, distructors, and operator=

// if we write: class Empty {};
// we get:

class Empty {
    public:
        Empty() {} // ctor
        Empty(const Empty &rhs) {} // copy-ctor

        ~Empty() {}

        Empty& operator=(const Empty &rhs) {}
};

int main()
{
    Empty e1;       // default ctor

    Empty e2(e1);   // copy-ctor

    e2 = e1;        // operator=
}
