#include "tools.h"

template<class InIt, class OutIt>
OutIt my_move(InIt first1, InIt last1, OutIt destination)
{
    while (first1 != last1)
    {
        *destination = std::move(*first1);
        ++first1;
        ++destination;
    }
    return destination;
}

template<class It>
class my_move_iterator
{
    private:
        using OriginalRefType = typename std::iterator_traits<It>::reference;
        It iter;
    public:
        using iterator_category = typename std::iterator_traits<It>::iterator_category;
        using difference_type   = typename std::iterator_traits<It>::difference_type;
        using value_type        = typename std::iterator_traits<It>::value_type;
        using pointer           = It;
        using reference         = std::conditional_t<
                                        std::is_reference_v<OriginalRefType>,
                                        std::remove_reference_t<OriginalRefType>&&,
                                        OriginalRefType
                                  >;

        my_move_iterator() = default;

        explicit my_move_iterator(It it) : iter(std::move(it)) {}

        template<class U>
        my_move_iterator(const my_move_iterator<U>& m) : iter(m.base()) {}

        template<class U>
        auto& operator=(const my_move_iterator<U>& m)
        {
            iter = m.base();
            return *this;
        }

        It base() const
        {
            return iter;
        }

        reference operator*()
        {
            return static_cast<reference>(*iter);
        }

        It operator->()
        {
            return iter;
        }

        decltype(auto) operator[] (difference_type n) const
        {
            return *std::move(iter[n]);
        }

        auto& operator++()
        {
            ++iter;
            return *this;
        }

        auto& operator++(int)
        {
            auto result = *this;
            ++*this;
            return result;
        }

        auto& operator--()
        {
            --iter;
            return *this;
        }

        auto& operator--(int)
        {
            auto result = *this;
            --*this;
            return result;
        }

        auto& operator+=(difference_type n) const
        {
            iter += n;
            return *this;
        }

        auto& operator-=(difference_type n) const
        {
            iter -= n;
            return *this;
        }
};

template<class InputIterator>
auto my_make_move_iterator(InputIterator& c)
{
    return my_move_iterator(c);
}

int main()
{
    {
        std::vector<int> vv {generate_random_vector(10, -100, 169, 69)}, zz(10);
        std::cerr << vv << " " << zz << std::endl;
        my_move(std::begin(vv), std::end(vv), std::begin(zz));
        std::cerr << vv << " " << zz << std::endl;
    }
    {
        std::vector<int> vv {generate_random_vector(10, -100, 169, 42)}, zz(10);
        std::cerr << vv << " " << zz << std::endl;
/*        std::copy(
            my_make_move_iterator(vv.begin()),
            my_make_move_iterator(vv.end()),
            zz.begin()
        );*/ // ???
        std::cerr << vv << " " << zz << std::endl;
    }
}
