#include "tools.h"

template<class Derived>
class addable
{
    public:
        friend auto operator+(Derived lhs, const Derived& rhs)
        {
            lhs += rhs;
            return lhs;
        }
};

int main()
{

}
