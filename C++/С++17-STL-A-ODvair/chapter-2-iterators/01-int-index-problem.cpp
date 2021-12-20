#include <iostream>

using namespace std;

template <typename Container>
void double_each_element(Container &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        arr.at(i) *= 2;
    }
}

class list_of_ints
{
    private:
        struct node
        {
            int data;
            node *next;
        };

        node *head_ = nullptr;
        node *tail_ = nullptr;
        int size_ = 0;
    public:
        int size() const
        {
            return size_;
        }

        int& at(int i)
        {
            if (i >= size_)
            {
                throw std::out_of_range("at");
            }
            node *p = head_;
            for (int j = 0; j < i; ++j)
            {
                p = p->next;
            }
            return p->data;
        }

        void push_back(int value)
        {
            node *new_tail = new node{value, nullptr};

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
            for (node *next, *p = head_; p != nullptr; p = next)
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

    for (size_t i = 0; i < lst.size(); ++i)
    {
        cout << lst.at(i) << endl;
    }
}
