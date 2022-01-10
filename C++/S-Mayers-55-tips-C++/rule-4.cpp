// Rule #4
// always initialize objects

#include <iostream>
#include <list>

class PhoneNumber
{};

class ABEntry
{
    public:
        ABEntry(const std::string &name,
                const std::string& address,
                const std::list<PhoneNumber> &phones)
        /*
        * {   // it's assignment not initialization
        *     theName = name;
        *     theAdress = address;
        *     thePhones = phones;
        *     numTimesConsulted = 0;
        * }
        */
        //  And this is initialization
        :   theName(name),
            theAdress(address),
            thePhones(phones),
            numTimesConsulted(0)
        {}
    private:
        std::string theName;
        std::string theAdress;
        std::list<PhoneNumber> thePhones;
        int numTimesConsulted;
};

int main()
{
    {
        int x = 0;

        const char * text = "String in C-style";
    }
    {
        double d;           // Only here we could not initialize
        std::cin >> d;
    }
    {
        std::string a = "a", b = "b";
        std::list<PhoneNumber> c;
        ABEntry abe(a, b, c);
    }
}
