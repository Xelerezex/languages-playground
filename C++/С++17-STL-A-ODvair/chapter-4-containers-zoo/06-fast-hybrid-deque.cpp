#include "tools.h"

int main()
{
    std::vector<int> vec = {1, 2 ,3 ,4};
    std::deque<int> deq = {1, 2 ,3 ,4};

    int *vec_p = &vec[2];
    int *deq_p = &deq[2];

    for (int i = 0; i < 1'000; ++i)
    {
        vec.push_back(i);
        deq.push_back(i);
    }

    ASSERT(vec_p != &vec[2]);
    ASSERT(deq_p == &deq[2]);
}
