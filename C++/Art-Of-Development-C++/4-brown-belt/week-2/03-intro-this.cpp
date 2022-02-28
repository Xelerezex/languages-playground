#include "test_runner.h"

// #include <iostream>
// using namespace std;

template <typename T>
class SimpleVector
{
    public:
        SimpleVector() = default;
        explicit SimpleVector(size_t size);
        SimpleVector(const SimpleVector& other);
        SimpleVector(SimpleVector&& other);
        ~SimpleVector();

        void operator=(const SimpleVector& other);
        void operator=(SimpleVector&& other);
        T& operator[] (size_t index);

        T* begin();
        T* end();
        const T* begin() const;
        const T* end()   const;

        size_t Size() const;
        size_t Capacity() const;
        void PushBack(const T& value);

    private:
        T* data = nullptr;
        size_t size = 0;
        size_t capacity = 0;
};

template<typename T>
SimpleVector<T>::SimpleVector(size_t size)
    : data(new T[size]),
      size(size),
      capacity(size)
{
    std::cout << this << std::endl;
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
    : data(new T[other.capacity]),
      size(other.size),
      capacity(other.capacity
)
{
    std::copy(other.begin(), other.end(), begin());
}


template<typename T>
SimpleVector<T>::SimpleVector(SimpleVector<T>&& other)
    : data(other.data),
      size(other.size),
      capacity(other.capacity
)
{
    other.data = nullptr;
    other.size = other.capacity = 0;
}

template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete[] data;
}


template <typename T>
void SimpleVector<T>::operator=(const SimpleVector<T>& other)
{
    if (this != &other)
    {
        delete[] data;
        data = new T[other,capacity];
        size = other.size;
        capacity = other.capacity;
        std::copy(other.begin(), other.end(), begin());
    }
}

template <typename T>
void SimpleVector<T>::operator=(SimpleVector<T>&& other)
{
    if (this != &other)
    {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = other.capacity = 0;
    }
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
size_t SimpleVector<T>::Size() const
{
    return size;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const
{
    return capacity;
}

template <typename T>
void SimpleVector<T>::PushBack(const T& value)
{
    if (size >= capacity)
    {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        std::copy(begin(), end(), new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
    data[size++] = value;
}

template <typename T>
T* SimpleVector<T>::begin()
{
    return data;
}

template <typename T>
const T* SimpleVector<T>::begin() const
{
    return data;
}

template <typename T>
T* SimpleVector<T>::end()
{
    return data + size;
}

template <typename T>
const T* SimpleVector<T>::end() const
{
    return data + size;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const SimpleVector<T>& rhs)
{
    os << "Size = " << rhs.Size()
       << " Items:";

    for (const auto& x : rhs)
    {
        os << ' ' << x;
    }
    return os;
}

int main()
{
    SimpleVector<int> source1(5);
    SimpleVector<int> source2(5);

//    std::cout << &source1 << ' ' << &source2 << std::endl;
    for (size_t i = 0; i < source1.Size(); ++i)
    {
        source1[i] = i;
    }

    std::cout << source1 << std::endl;
    source1 = source1;
    std::cout << source1 << std::endl;
}
