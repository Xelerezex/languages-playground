#include <iostream>
#include <type_traits>

using namespace std;

template <typename Container>
void double_each_element(Container &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        arr.at(i) *= 2;
    }
}

struct list_node
{
    int data;
    list_node *next;
};

template <bool Const>
class list_of_ints_iterator
{
    private:
        friend class list_of_ints;
        friend class list_of_ints_iterator<!Const>;

        using node_pointer = std::conditional_t<Const, const list_node*, list_node*>;
        using reference    = std::conditional_t<Const, const int&, int&>;

        node_pointer ptr_;

        explicit list_of_ints_iterator(node_pointer p) : ptr_(p) {}
    public:
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
            auto it = *this;
            ++*this;
            return it;
        }

        template <bool R>
        bool operator==(const list_of_ints_iterator<R> &rhs) const
        {
            return ptr_ == rhs.ptr_;
        }

        template <bool R>
        bool operator!=(const list_of_ints_iterator<R> &rhs) const
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
        size_t size_ = 0;
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

        size_t size() const
        {
            return size_;
        }

        int& at(size_t i)
        {
            if (i >= size_)
            {
                throw std::out_of_range("at");
            }
            list_node *p = head_;
            for (size_t j = 0; j < i; ++j)
            {
                p = p->next;
            }
            return p->data;
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

int main()
{
    list_of_ints lst;

    for (const auto l : {1, 7, 18, 9, 4})
    {
        lst.push_back(l);
    }

    double_each_element(lst);               // O(n^2)

    for (const auto l : lst)                // !!!!!!!
    {
        cout << l << endl;
    }
}
