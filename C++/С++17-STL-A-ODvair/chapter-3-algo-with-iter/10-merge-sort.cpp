#include "tools.h"

template<typename RandomIt>
void my_sort(RandomIt a, RandomIt b)
{
    auto n = std::distance(a, b);
    if (n >= 2)
    {
        auto mid = a + (n / 2);
        std::sort(a, mid);
        std::sort(mid, b);
        std::inplace_merge(a, mid, b);
    }
}


int main()
{
    std::vector<int> v {6, 4, 5, 1, 3, 2, 7, 8};
    my_sort(v.begin(), v.end());
    std::cerr << v << std::endl;
}
