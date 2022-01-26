#include "tools.h"


class Widget
{
    public:
        virtual bool IsEqualTo(Widget const *b) const;
        virtual int GetHashValue() const;
};

struct myhash
{
    size_t operator()(const Widget *w) const
    {
        return w->GetHashValue();
    }
};

struct myequal
{
    size_t operator()(const Widget *a, const Widget *b) const
    {
        return a->IsEqualTo(b);
    }
};

int main()
{
    {
        std::unordered_set<Widget *, myhash, myequal> s;
    }
}
