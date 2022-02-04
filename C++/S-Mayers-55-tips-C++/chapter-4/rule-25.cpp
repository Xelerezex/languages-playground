// Rule #25
// Think about noexcept swap

#include<vector>

template<typename T>
void swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

class WidgetImpl
{
    public:

    private:
        int a, b, c;
        std::vector<double> v;
};

class Widget
{
    public:
        Widget(const Widget& rhs);

        Widget& operator=(const Widget& rhs)
        {
            *pimpl = * (rhs.pimpl);
        }

    private:
        WidgetImpl *pimpl;
};

template <>
void swap<Widget>(Widget& a, Widget& b)
{
    swap(a.pimpl, b.pimpl);
}

int main()
{

}
