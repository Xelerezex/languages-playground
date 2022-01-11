#include <forward_list>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <vector>
#include <list>

template<class InputIterator, class UnaryPredicate>
InputIterator my_find_if(InputIterator first, InputIterator last, UnaryPredicate p)
{
    for (; first != last; ++first)
    {
        if (p(*first))
        {
            return first;
        }
    }
    return last;
}

template<class It, class U>
It my_find_if_not(It first, It last, U p)
{
    return my_find_if(first, last, [&](auto&& e){ return !p(e); });
}

template<class It, class T>
It my_find(It first, It last, T value)
{
    return my_find_if(first, last, [&](auto&& e){ return e == value; });
}

template<class It, class UnaryPredicate>
bool my_all_of(It first, It last, UnaryPredicate p)
{
    return my_find_if_not(first, last, p) == last;
}

template<class It, class UnaryPredicate>
bool my_any_of(It first, It last, UnaryPredicate p)
{
    return my_find_if(first, last, p) != last;
}

template<class It, class UnaryPredicate>
bool my_none_of(It first, It last, UnaryPredicate p)
{
    return my_find_if(first, last, p) == last;
}

template<class It, class FwdIt>
It my_find_first_of(It first, It last, FwdIt targetfirst, FwdIt targetlast)
{
    return my_find_if(first, last,
        [&] (auto&& e) {
            return my_any_of(targetfirst, targetlast,
                [&] (auto&& t) {
                    return e == t;
                }
            );
        }
    );
}

template<class It, class FwdIt, class BinaryPredicate>
It my_find_first_of(It first, It last, FwdIt targetfirst, FwdIt targetlast, BinaryPredicate p)
{
    return my_find_if(first, last,
        [&] (auto&& e) {
            return my_any_of(targetfirst, targetlast,
                [&] (auto&& t) {
                    return p(e, t);
                }
            );
        }
    );
}

template<class T> constexpr bool is_random_access_iterator_v =
    std::is_base_of_v<std::random_access_iterator_tag, typename std::iterator_traits<T>::iterator_category>;

template<class It1, class It2, class B>
auto my_mismatch(It1 first1, It1 last1, It2 first2, It2 last2, B p)
{
    while (first1 != last1 && first2 != last2 && p(*first1, *first2))
    {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

template<class It1, class It2>
auto my_mismatch(It1 first1, It1 last1, It2 first2, It2 last2)
{
    return std::mismatch(first1, last1, first2, last2, std::equal_to<>{});
}

template<class It1, class It2, class B>
bool equal(It1 first1, It1 last1, It2 first2, It2 last2, B p)
{
    if constexpr (is_random_access_iterator_v<It1> && is_random_access_iterator_v<It2>)
    {
        if ((last2 - first2) != (last1 - first1))
        {
            return false;
        }
    }

    return std::mismatch(first1, last1, first2, last2, p) == std::make_pair(last1, last2);
}

template<class It1, class It2>
bool equal(It1 first1, It1 last1, It2 first2, It2 last2)
{
    return std::equal(first1, last1, first2, last2, std::equal_to<>{});
}

int main()
{
    {
        constexpr int N = 10;
        int a[N];

        for (int i = 0; i < N; ++i) {}


        for (int i = 0; i <= N; ++i) {} // Potential error

        std::count_if(std::begin(a), std::end(a), [] (int) { return true; });

        std::count_if(std::begin(a), std::end(a) - 1, [] (int) { return true; }); // Potential error

        std::count_if(std::begin(a), std::begin(a), [] (int) { return true; });
    }
    {
        int a[] {1, 2, 3, 4, 5};
        std::list<int> lst {1, 2, 3, 4, 5};
        std::forward_list<int> flst {1, 2, 3, 4, 5};

        assert(std::distance(std::begin(a), std::end(a)) == 5);
        assert(std::distance(std::begin(lst), std::end(lst)) == 5);
        assert(std::distance(std::begin(flst), std::end(flst)) == 5);

        assert(std::distance(std::end(a), std::begin(a)) == -5);            // !!!!!
        // assert(std::distance(std::end(lst), std::begin(lst)) == 1);
        // std::distance(std::end(flst), std::begin(flst));
    }
    {
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
        std::vector<int> sub_v = {3, 7, 8};

        std::cout << *my_find_if(std::begin(v), std::end(v), [](int a){ return a >3; }) << std::endl;
        std::cout << *my_find_if_not(std::begin(v), std::end(v), [](int a){ return a <= 7; }) << std::endl;
        std::cout << *my_find(std::begin(v), std::end(v), 2) << std::endl;

        std::cout << std::boolalpha;
        std::cout << my_all_of(std::begin(v), std::end(v), [](int a){ return a < 10; }) << std::endl;
        std::cout << my_any_of(std::begin(v), std::end(v), [](int a){ return a == 5; }) << std::endl;
        std::cout << my_none_of(std::begin(v), std::end(v), [](int a){ return a > 10; }) << std::endl;

        std::cout << *my_find_first_of(std::begin(v), std::end(v), std::begin(sub_v), std::end(sub_v)) << std::endl;
        std::cout << *my_find_first_of(std::begin(v), std::end(v), std::begin(sub_v), std::end(sub_v), [](int a, int b){ return a <= 7; }) << std::endl;
    }
    {   // don't stop until 'hello'
        std::istream_iterator<char> ii(std::cin);
        std::istream_iterator<char> iend{};
        std::string s = "hello";

        std::find_first_of(ii, iend, s.begin(), s.end());
    }
    {
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        std::vector<int> sub_v = {10, 11, 12};

        std::cout << *my_mismatch(std::begin(v), std::end(v), std::begin(sub_v), std::end(sub_v), std::equal_to<>{}).first << " "
                  << *my_mismatch(std::begin(v), std::end(v), std::begin(sub_v), std::end(sub_v), std::equal_to<>{}).second << std::endl;
    }
}
