#include <iterator>
#include <iostream>
#include <cassert>

struct list_node
{
    int data;
    list_node *next;
};

template <bool Const>
class list_of_ints_iterator
{
    friend class list_of_ints;
    friend class list_of_ints_iterator<!Const>;

    private:
        using node_pointer = std::conditional_t<Const, const list_node*, list_node*>;
        node_pointer ptr_;

        explicit list_of_ints_iterator(node_pointer p)
            : ptr_(p)
        {}
    public:
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = std::conditional_t<Const, const int*, int*>;
        using reference         = std::conditional_t<Const, const int&, int&>;
        using iterator_category = std::forward_iterator_tag;

        reference operator*() const
        {
            return ptr_->data;
        }

        auto& operator++()
        {
            ptr_ = ptr_->next;
            return *this;
        }

        auto operator++(int)
        {
            auto result = *this;
            ++*this;
            return result;
        }

        template <bool R>
        bool operator==(const list_of_ints_iterator<R>& rhs) const
        {
            return ptr_ == rhs.ptr_;
        }

        template<bool R>
        bool operator!=(const list_of_ints_iterator<R>& rhs) const
        {
            return ptr_ != rhs.ptr_;
        }

        operator list_of_ints_iterator<true>() const
        {
            return list_of_ints_iterator<true>{ptr_};
        }
};

class list_of_ints
{
    private:
        list_node *head_ = nullptr;
        list_node *tail_ = nullptr;
        std::size_t size_ = 0;
    public:
        using const_iterator = list_of_ints_iterator<true>;
        using iterator       = list_of_ints_iterator<false>;

        iterator begin()
        {
            return iterator{head_};
        }

        iterator end()
        {
            return iterator{nullptr};
        }

        const_iterator begin() const
        {
            return const_iterator{head_};
        }

        const_iterator end() const
        {
            return const_iterator{nullptr};
        }

        std::size_t size() const
        {
            return size_;
        }

        void push_back(int value)
        {
            list_node *new_tail = new list_node{value, nullptr};

            if (tail_)
            {
                tail_->next = new_tail;
            }
            else
            {
                head_ = new_tail;
            }
            tail_ = new_tail;
            size_ += 1;
        }

        ~list_of_ints()
        {
            for (list_node *next, *p = head_; p != nullptr; p = next)
            {
                next = p->next;
                delete p;
            }
        }
};

template <typename Iterator>
auto distance(Iterator begin, Iterator end)
{
    using Traits = std::iterator_traits<Iterator>;

    if constexpr (
        std::is_base_of_v<std::random_access_iterator_tag,
        typename Traits::iterator_category>
    )
    {
        return (end - begin);
    }
    else
    {
        auto result = typename Traits::difference_type{};
        for (auto it = begin; it != end; ++it)
        {
            ++result;
        }
        return result;
    }
}

template <typename Iterator, typename Predicate>
auto count_if(Iterator begin, Iterator end, Predicate pred)
{
    using Traits = std::iterator_traits<Iterator>;
    auto sum = typename Traits::difference_type{};

    for (auto it = begin; it != end; ++it)
    {
        if (pred(*it))
        {
            ++sum;
        }
    }
    return sum;
}

int main()
{
    list_of_ints lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    int64_t s = count_if(lst.begin(), lst.end(),
        [] (int i) {
            return i >= 2;
        }
    );
    assert(s == 2);

    int64_t d = distance(lst.begin(), lst.end());
    assert(d == 3);
}
