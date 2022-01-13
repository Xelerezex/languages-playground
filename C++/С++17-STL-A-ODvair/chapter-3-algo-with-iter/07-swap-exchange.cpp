#include "tools.h"

namespace my
{
    class obj
    {
        private:
            int v;
        public:
            obj(int value) : v(value) {}

            void swap(obj& other)
            {
                using std::swap;
                swap(this->v, other.v);
            }
    };

    void swap(obj& a, obj& b)
    {
        a.swap(b);
    }
}

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    while (first != last)
    {
        --last;
        if (first == last)
        {
            break;
        }
        using std::swap;

        swap(*first, *last);
        ++first;
    }
}

void reverse_words_in_place(std::string& s)
{
    my_reverse(s.begin(), s.end());

    for (auto it = s.begin(); true; ++it)
    {
        auto next = std::find(it, s.end(), ' ');
        std::reverse(it, next);

        if (next == s.end())
        {
            break;
        }
        it = next;
    }
}

template<class It>
auto rev(It it)
{
    return std::reverse_iterator(it);
}

template<class InnerIt>
auto unrev(std::reverse_iterator<InnerIt> it)
{
    return it.base();
}

template<class BidirIt, class Unary>
auto my_partition(BidirIt first, BidirIt last, Unary p)
{
    first = std::find_if_not(first, last, p);

    while (first != last)
    {
        last = unrev(std::find_if(rev(last), rev(first), p));
        if (first == last)
        {
            break;
        }
        using std::swap;

        swap(*first++, *++last);

        first = std::find_if_not(first, last, p);
    }
    return first;
}

int main()
{
    {
        int i1 = 1, i2 = 2;
        std::vector<int> v1 = {1}, v2 = {2};
        my::obj m1 = 1, m2 = 2;
        using std::swap;
        swap(i1, i2);       // std::swap
        swap(v1, v2);       // std::swap
        swap(m1, m2);       // my::swap
    }
    {
        std::string s = "a b c d e f z";
        reverse_words_in_place(s);
        ASSERT_EQUAL(s, "z f e d c b a");
    }
    {
        std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5};
        auto it = my_partition(v.begin(), v.end(),
            [] (int x) {
                return x % 2 == 0;
            }
        );
        ASSERT_EQUAL(*(it), *(v.begin() + 3));
        std::vector<int> expected = {6, 2, 4, 1, 5, 9, 1, 3, 5};
        ASSERT_EQUAL(v, expected);
    }
}
