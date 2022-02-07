#include "tools.h"

struct Super
{
    int first, second;
    Super(int a, int b) : first(a), second(b)
    {}

    ~Super() { puts("destroying Super"); }
};

auto get_second()
{
    auto p = std::make_shared<Super>(4, 2);
    return std::shared_ptr<int>(p, &p->second);
}

int main()
{
    {
        std::shared_ptr<int> pa, pb, pc;

        pa = std::make_shared<int>();

        pb = pa;

        pc = std::move(pa);

        pb = nullptr;
    }
    {
        std::shared_ptr<int> q = get_second();
        puts("accessing Super::second");
        assert(*q == 2);
    }
    {   // Do not allow double control
        std::shared_ptr<int> pa, pb, pc;

        pa = std::make_shared<int>();

        pb = pa;

        pc = std::shared_ptr<int>(pb.get());      // ERROR!!!
        assert(pb.use_count() == 2);
        assert(pb.use_count() == 1);

        pc = nullptr;

        *pb;
    }
}
