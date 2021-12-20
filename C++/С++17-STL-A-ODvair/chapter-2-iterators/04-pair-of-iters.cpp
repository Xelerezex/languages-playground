#include <vector>
#include <iostream>

template <class L>
std::ostream& operator << (std::ostream& os, const std::vector<L>& l);


template <class Iterator>
void double_each_element (Iterator begin, Iterator end)
{
    for (auto it = begin; it != end; ++it)
    {
        *it *= 2;
    }
}

int main()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6};
    double_each_element(v.begin(), v.end());
    std::cout << v << std::endl;

    double_each_element(v.begin(), v.begin() + 3);
    std::cout << v << std::endl;

    double_each_element(&v[0], &v[3]);
    std::cout << v << std::endl;
}


//-------------FOR-VECTOR
template <class L>
std::ostream& operator << (std::ostream& os, const std::vector<L>& l)
{
    os << "[";
    bool first = true;

    for(const auto& i : l)
    {
        if (!first)
        {
            os << ", ";
        }

        first = false;
        os << i;
    }
    return os << "]";
}
