// Rule #7
// Do not allow exception went from dtors
#include <vector>

class Widget
{
    public:
        ~Widget() { throw exception; } // If exception throw in first, all other 9 from vectors doesn't delete
};

int main()
{
    std::vector<Widget> v(10);
}
