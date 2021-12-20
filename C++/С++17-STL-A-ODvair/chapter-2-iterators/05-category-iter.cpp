#include <iostream>
#include <vector>
#include <cassert>

/*
template <typename Iterator>
int my_distance (Iterator begin, Iterator end)
{
    int sum = 0;
    for (auto it = begin; it != end; ++it)
    {
        sum += 1;
    }
    return sum;
}
*/

// Normal decision
template <typename Iterator>
int my_distance (Iterator begin, Iterator end)
{
    return end - begin;
}

template <typename Iterator, typename Predicate>
int count_if (Iterator begin, Iterator end, Predicate pred)
{
    int sum = 0;
    for (auto it = begin; it != end; ++it)
    {
        if (pred(*it))
        {
            sum += 1;
        }
    }
    return sum;
}

int main()
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    int number_above = count_if(v.begin(), v.end(), [](int e){ return e > 5; });
    int number_below = count_if(v.begin(), v.end(), [](int e){ return e > 5; });

    int total = my_distance(v.begin(), v.end());       // AMBIGUOUS DECISION

    assert(number_above == 2);
    assert(number_below == 5);
    assert(total == 8);
}
