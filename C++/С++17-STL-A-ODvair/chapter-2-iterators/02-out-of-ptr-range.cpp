#include <iostream>

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

class list_of_ints_iterator
{
    private:
        list_node *ptr_;

        friend class list_of_ints;
        explicit list_of_ints_iterator(list_node *p) : ptr_(p) {}
    public:
        int& operator*() const
        {
            return ptr_->data;
        }

        list_of_ints_iterator& operator++()
        {
            ptr_ = ptr_->next;
            return *this;
        }

        list_of_ints_iterator operator++(int)
        {
            auto it = *this;
            ++*this;
            return it;
        }

        bool operator==(const list_of_ints_iterator &rhs) const
        {
            return ptr_ == rhs.ptr_;
        }

        bool operator!=(const list_of_ints_iterator &rhs) const
        {
            return ptr_ != rhs.ptr_;
        }
};

class list_of_ints
{
    private:
        list_node *head_ = nullptr;
        list_node *tail_ = nullptr;
        size_t size_ = 0;
    public:
        using iterator = list_of_ints_iterator;
        iterator begin()
        {
            return iterator{head_};
        }

        iterator end()
        {
            return iterator{nullptr};
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
