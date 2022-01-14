#include "tools.h"

template<class FwdIt, class T>
FwdIt my_remove(FwdIt first, FwdIt last, const T& value)
{
    auto out = std::find(first, last, value);
    if (out != last)
    {
        auto in = out;
        while (++in != last)
        {
            if (*in == value)
            {
            }
            else
            {
                *out++ = std::move(*in);
            }
        }
    }
    return out;
}

namespace my
{
    template<class BidirIt, class T>
    BidirIt unstable_remove(BidirIt first, BidirIt last, const T& value)
    {
        while (true)
        {
            first = std::find(first, last, value);
            do
            {
                if (first == last)
                {
                    return last;
                }
                --last;
            }
            while (*last == value);
            *first = std::move(*last);
            ++first;
        }
    }
}

int main()
{
    {
        std::vector<int> vec {1, 3, 3, 4, 6, 8};

        auto first_3 = std::stable_partition(
            vec.begin(), vec.end(), [] (int v) { return v != 3; }
        );

        ASSERT_EQUAL(vec, (std::vector{1, 4, 6, 8, 3, 3}));

        vec.erase(first_3, vec.end());

        ASSERT_EQUAL(vec, (std::vector{1, 4, 6, 8}));
    }
    {
        std::vector<int> vec = {1, 3, 3, 4, 6, 8};
        auto new_end = std::remove(
            vec.begin(), vec.end(), 3
        );

        ASSERT_EQUAL(vec, (std::vector{1, 4, 6, 8, 6, 8}));

        vec.erase(new_end, vec.end());

        ASSERT_EQUAL(vec, (std::vector{1, 4, 6, 8}));

        vec.erase(
            std::remove(vec.begin(), vec.end(), 3),
            vec.end()
        );

        auto first = std::lower_bound(vec.begin(), vec.end(), 3);
        auto last = std::upper_bound(first, vec.end(), 3);
        vec.erase(first, last);
    }
    // erase-delete
    {
        std::vector<int> vec {1, 2, 2, 3, 3, 3, 1, 3, 3};

        vec.erase(
            std::unique(vec.begin(), vec.end()),
            vec.end()
        );

        ASSERT_EQUAL(vec, (std::vector{1, 2, 3, 1, 3}));
    }
    {
        std::vector<int> vec {4, 1, 3, 6, 3, 8};

        vec.erase(
            my::unstable_remove(vec.begin(), vec.end(), 3),
            vec.end()
        );

        ASSERT_EQUAL(vec, (std::vector{4, 1, 8, 6}));
    }
}
