#include "tools.h"

template<class RandomIt>
void my_push_heap(RandomIt a, RandomIt b)
{
    auto child = ((b-1) - a);
    while (child != 0)
    {
        auto parent = (child - 1) / 2;
        if (a[child] < a[parent])
        {
            return;
        }
        std::iter_swap(a + child, a + parent);
        child = parent;
    }
}

template<class RandomIt>
void my_pop_heap(RandomIt a, RandomIt b)
{
    using DistanceT = decltype(b - a);
    std::iter_swap(a, b-1);
    DistanceT parent = 0;
    DistanceT new_heap_size = ((b - 1) - a);

    while (true)
    {
        auto leftchild = 2 * parent + 1;
        auto rightchild = 2 * parent + 2;
        if (leftchild >= new_heap_size)
        {
            return;
        }
        auto biggerchild = leftchild;
        if (rightchild < new_heap_size && a[leftchild] < a[rightchild])
        {
            biggerchild = rightchild;
        }
        if (a[biggerchild] < a[parent])
        {
            return;
        }
        std::iter_swap(a + parent, a + biggerchild);
        parent = biggerchild;
    }
}

template<class RandomIt>
void my_make_heap(RandomIt a, RandomIt b)
{
    for (auto it = a; it != b; )
    {
        my_push_heap(a, ++it);
    }
}

template<class RandomIt>
void my_sort_heap(RandomIt a, RandomIt b)
{
    for (auto it = b; it != a; --it)
    {
        my_pop_heap(a, it);
    }
}

template<class RandomIt>
void my_sort(RandomIt a, RandomIt b)
{
    my_make_heap(a, b);
    my_sort_heap(a, b);
}

int main()
{
    {
        std::vector<int> v {1, 2, 3, 4, 5, 6};
        my_push_heap(v.begin(), v.end());
        std::cerr << v << std::endl;
    }
    {
        std::vector<int> v {1, 2, 3, 4, 5, 6};
        my_pop_heap(v.begin(), v.end());
        std::cerr << v << std::endl;
    }
    {
        std::vector<int> v {1, 2, 3, 4, 5, 6};
        my_make_heap(v.begin(), v.end());
        std::cerr << v << std::endl;
    }
    {
        std::vector<int> v {6, 4, 5, 1, 3, 2};
        my_sort_heap(v.begin(), v.end());
        std::cerr << v << std::endl;
    }
    {
        std::vector<int> v {6, 4, 5, 1, 3, 2, 7, 8};
        my_sort(v.begin(), v.end());
        std::cerr << v << std::endl;
    }
}
