#include <iostream>
#include <vector>
#include <cassert>

template <class Container>
int count(const Container &container)
{
    int sum = 0;
    for (auto &&elt : container)
    {
        sum += 1;
    }
    return sum;
}


template <class Container, class Predicate>
int count_if(const Container &container, Predicate pred)
{
    int sum = 0;
    for (auto &&elt : container)
    {
        if (pred(elt)){
            sum += 1;
        }
    }
    return sum;
}


int main()
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    assert(count(v) == 8);

    int number_above = count_if(v,
        [] (int e) {
            return e > 5;
        }
    );

    int number_below = count_if(v,
        [] (int e) {
            return e < 5;
        }
    );

    assert(number_above == 2);
    assert(number_below == 5);

    std::cout << "OK!" << std::endl;
}
