#include <mutex>
#include <stdexcept>
#include <climits>

class hierarchical_mutex
{

};

int main()
{
    hierarchical_mutex m1(42);
    hierarchical_mutex m1(69);
}
