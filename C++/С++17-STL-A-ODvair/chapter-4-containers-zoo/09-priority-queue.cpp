#include "tools.h"

int main()
{
    std::priority_queue<int> pq1;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq2;

    for (int v : {3, 1, 4, 1, 5, 9})
    {
        pq1.push(v);
        pq2.push(v);
    }

    ASSERT(pq1.top() == 9);
    ASSERT(pq2.top() == 1);
}
