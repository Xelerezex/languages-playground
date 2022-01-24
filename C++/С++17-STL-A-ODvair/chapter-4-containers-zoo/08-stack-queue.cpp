#include "tools.h"

int main()
{
    {
        std::stack<int> stk;
        stk.push(3);
        stk.push(1);
        stk.push(4);
        ASSERT(stk.top() == 4);
        stk.pop();
        ASSERT(stk.top() == 1);
        stk.pop();
        ASSERT(stk.top() == 3);
    }
    {
        std::stack<int> a, b;
        a.push(3);
        a.push(1);
        a.push(4);
        b.push(2);
        b.push(7);
        ASSERT(a != b);
        ASSERT(a.top() < b.top());
        ASSERT(a > b);
    }
}
