// Explicitly forbid the compiler to generate functions
// that you don't need

/* First Variant
* class HomeForSale
* {
*     public:
*         HomeForSale() {}
*     private:
*         HomeForSale(const HomeForSale&);
*         HomeForSale& operator=(const HomeForSale&);
};
*/

// Better way to do it

class Uncopyable
{
    protected:
        Uncopyable() {}
        ~Uncopyable() {}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale : private Uncopyable
{

};

int main()
{
    HomeForSale h1;
    HomeForSale h2;

    // HomeForSale h3(h1);  // if uncomment, error will throw in compile time

    // h1 = h2;
}
