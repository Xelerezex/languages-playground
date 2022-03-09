#include "tools.h"

int main()
{
    std::set<int> numbers = {3, 7, 5, 6, 20, 4, 22, 17, 9};

    auto it = std::find(
        begin(numbers), end(numbers), 4
    );

    *it = 21;

    for (auto x : numbers)
    {
        std::cout << x << ' ';
    }
}
