#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;


template <typename T>
class SimpleVector {
    public:
        explicit SimpleVector(size_t size) {
            data = new T[size];
            end_ = data + size;
        }

        T& operator[] (size_t index) {
            return data[index];
        }

        T* begin() { return data; }
        T* end()   { return end_; }

        // Can't change exactly *date* if const T*
        const T* begin() const { return data; }
        const T* end()   const { return end_; }

        ~SimpleVector() {
            delete[] data;
        }

    private:
        T* data;
        T* end_;
};

template <typename T>
void Print(const SimpleVector<T>& v) {
    for (const auto& x : v) {
        cout << x << '\n';
    }
}

int main() {
    int x = 5;                      // Object
    int* px = &x;                   // Pointer on Object
    const int* cpx = &x;            // Pointer on CONST Object
    int* const pxc = &x;            // CONST Pointer on Object
    const int* const cpxc = &x;     // CONST Pointer on CONST Object
}
