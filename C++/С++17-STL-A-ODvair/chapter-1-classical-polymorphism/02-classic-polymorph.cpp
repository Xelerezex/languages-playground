#include <iostream>

using namespace std;

class container_of_ints
{
    public:
        virtual int size() const = 0;
        virtual int& at(int) = 0;
};

class array_of_ints : public container_of_ints
{
    private:
        int data[10] = {};
    public:
        int size() const override { return 10; }
        int& at(int i) override { return data[i]; }
};

class list_of_ints : public container_of_ints
{
    private:
        struct node
        {
            int data;
            node *next;
        };
        node *head_ = nullptr;
        int size_ = 0;
    public:
        int size() const override { return size_; }
        int& at(int i) override
        {
            if (i >= size())
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
        ~list_of_ints(){}
};

void double_each_element(container_of_ints &arr)  // OBJECT ORIENTED FUNCTION
{
    for (int i = 0; i < arr.size(); ++i)
    {
        arr.at(i) *= 2;
    }
}

int main()
{
    array_of_ints arr;
    double_each_element(arr);

    list_of_ints lst;
    double_each_element(lst);
}
