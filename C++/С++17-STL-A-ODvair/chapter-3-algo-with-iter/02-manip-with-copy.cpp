#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
#include <vector>
#include <string>
#include <boost/iterator/iterator_facade.hpp>

template<class InIt, class OutIt>
OutIt my_copy(InIt first1, InIt last1, OutIt destination)
{
    while (first1 != last1)
    {
        *destination = *first1;
        ++first1;
        ++destination;
    }
    return destination;
}

class putc_iterator : public boost::iterator_facade<
    putc_iterator,
    const putc_iterator,
    std::output_iterator_tag
    >
{
    private:
        friend class boost::iterator_core_access;

        auto& dereference() const { return *this; }
        void increment() {}

        bool equal(const putc_iterator&) const { return false; }
    public:
        void operator= (char ch) const { putc(ch, stdout); }
};

namespace std
{
    template<class Container>
    class my_back_insert_iterator
    {
        private:
            using CtrValueType = typename Container::value_type;
            Container *c;
        public:
            using iterator_category = output_iterator_tag;
            using difference_type = void;
            using value_type = void;
            using pointer = void;
            using reference = void;

            explicit my_back_insert_iterator(Container &ctr) : c(&ctr) {}

            auto& operator*() { return *this; }
            auto& operator++() { return *this; }
            auto& operator++(int) { return *this; }

            auto& operator= (const CtrValueType& v) {
                c->push_back(v);
                return *this;
            }

            auto& operator= (CtrValueType&& v) {
                c->push_back(std::move(v));
                return *this;
            }
    };

    template<class Container>
    auto my_back_inserter(Container &c)
    {
        return my_back_insert_iterator<Container>(c);
    }
}

int main()
{
    {
        std::vector<int> v = {1, 2, 3, 4};
        std::vector<int> z(4);
        my_copy(std::begin(v), std::end(v), std::begin(z));
        for (const auto &i : v)
        {
            std::cout << i << " ";
        }
    }
    {
        std::string s = "hello";
        std::copy(s.begin(), s.end(), putc_iterator{});
    }
    {
        std::string s = "hello";
        std::vector<char> dest;
        std::copy(s.begin(), s.end(), my_back_inserter(dest));
        assert(dest.size() == 5);
    }
}
