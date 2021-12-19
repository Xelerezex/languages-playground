#include <iostream>

using namespace std;

class array_of_ints
{
    private:
        int data[10] = {};
    public:
        int size() const { return 10; }
        int& at(int i) { return data[i]; }
};

void double_each_element(array_of_ints &arr)  // MONOMORPHIC FUNCTION
{
    for (int i = 0; i < arr.size(); ++i)
    {
        arr.at(i) *= 2;
    }
}

int main()
{
    array_of_ints a;

    for (int i = 0; i < a.size(); ++i)
    {
        a.at(i) = i;
    }

    double_each_element(a);

    for (int i = 0; i < a.size(); ++i)
    {
        cout << a.at(i) << endl;
    }
}
