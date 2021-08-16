#include <iostream>


using namespace std;

class Lucky {
    public:
        bool isLucky(int number);        // FILTERING INPUT TYPE
        bool isLucky(bool n) = delete;   // Equivalent of throw method to private
        bool isLucky(char n) = delete;
        bool isLucky(double n) = delete;

    private:
        int number;
};


int main() {

    Lucky l;
    l.isLucky(1);
    /*l.isLucky('a');*/   // ERROR
    /*l.isLucky(true);*/  // ERROR
    /*l.isLucky(3.5f);*/  // ERROR


    return 0;
}
