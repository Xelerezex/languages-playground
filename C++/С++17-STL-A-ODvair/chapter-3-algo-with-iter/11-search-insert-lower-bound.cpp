#include "tools.h"

template<class FwdIt, class T, class C>
FwdIt my_lower_bound(FwdIt first, FwdIt last, const T& value, C lessthan)
{
    using DiffT = typename std::iterator_traits<FwdIt>::difference_type;
    FwdIt it;
    DiffT count = std::distance(first, last);

    while (count > 0)
    {
        DiffT step = count / 2;
        it = first;
        std::advance(it, step);
        if(lessthan(*it, value))
        {
            ++it;
            first = it;
            count -= step + 1;
        }
        else
        {
            count = step;
        }
    }
    return first;
}

template<class FwdIt, class T>
FwdIt my_lower_bound(FwdIt first, FwdIt last, const T& value)
{
    return std::lower_bound(first, last, value, std::less<>{});
}

int main()
{
    {
        std::vector<int> vec {3, 7};
        for (int value : {1, 5, 9})
        {
            auto it = my_lower_bound(vec.begin(), vec.end(), value);
            vec.insert(it, value);
        }
        ASSERT_EQUAL(vec, (std::vector{1, 3, 5, 7, 9}));
    }
    {
        std::vector<int> vec = {2, 3, 3, 3, 4};
        auto lower = std::lower_bound(vec.begin(), vec.end(), 3);
        auto upper = std::upper_bound(vec.begin(), vec.end(), 3);
        auto upper2 = std::upper_bound(lower, vec.end(), 3);
        ASSERT_EQUAL(*upper2, *upper);

        auto upper3 = std::find_if(lower, vec.end(), [](int v) {
            return v != 3;
        });
        ASSERT_EQUAL(*upper3, *upper);

        ASSERT(*lower >= 3);
        ASSERT(*upper > 3);
        ASSERT(std::all_of(lower, upper, [](int v){ return v == 3; }))
    }
}
