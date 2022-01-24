#include "tools.h"

int main()
{
    {
        std::list<int> a = {3, 6};
        std::list<int> b = {1, 2, 3, 5, 6};

        a.merge(b);
        ASSERT(b.empty());
        ASSERT((a == std::list{1, 2, 3, 3, 5, 6, 6}));
    }
    {
        std::list<int> lst = {3, 1, 4, 1, 5, 9, 2, 6, 5};
        auto begin = std::next(lst.begin(), 2);
        auto end = std::next(lst.end(), -2);

        std::list<int> sub;
        sub.splice(sub.begin(), lst, begin, end);
        sub.sort();
        lst.splice(end, sub);

        ASSERT(sub.empty());
        ASSERT((lst == std::list{3, 1, 1, 2, 4, 5, 9, 6, 5}));
    }
}
