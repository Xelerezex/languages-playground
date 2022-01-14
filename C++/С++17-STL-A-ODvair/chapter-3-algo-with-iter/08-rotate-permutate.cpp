#include "tools.h"

template<class FwdIt>
FwdIt rotate(FwdIt a, FwdIt mid, FwdIt b)
{
    auto result = a + (b - mid);
    std::reverse(a, b);
    std::reverse(a, result);
    std::reverse(result, b);
    return result;
}

int main()
{
    {
        std::vector<int> v = {1, 2, 3, 4, 5, 6};
        auto five = std::find(v.begin(), v.end(), 5);
        auto one = std::rotate(v.begin(), five, v.end());

        ASSERT_EQUAL(v, (std::vector<int>{5, 6, 1, 2, 3, 4}));
        ASSERT_EQUAL(*one, 1);
    }
    {
        std::vector<int> p = {10, 20, 30};
        std::vector<std::vector<int>> results;

        for (int i = 0; i < 6; ++i)
        {
            results.push_back(p);
            std::next_permutation(p.begin(), p.end());
        }

        std::vector<std::vector<int>> expected {
            {10, 20, 30},
            {10, 30, 20},
            {20, 10, 30},
            {20, 30, 10},
            {30, 10, 20},
            {30, 20, 10}
        };

        ASSERT_EQUAL(results, expected);
    }
}
