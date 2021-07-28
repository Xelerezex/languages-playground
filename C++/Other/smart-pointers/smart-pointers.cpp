#include <iostream>

template<typename T>
class SmartPointer {
    public:
        SmartPointer(T* ptr) : pointer(ptr) {
            std::cout << "[pointer created]" << std::endl;
        }
        ~SmartPointer() {
            std::cout << "[pointer deleted]" << std::endl;
            delete pointer;
        }

        T* GetPointer() {
            return pointer;
        }

        T operator*() {
            return *pointer;
        }

    private:
        T* pointer;
};

int main() {


    SmartPointer<int> sp = new int(13);
    std::cout << sp.GetPointer() << std::endl;
    std::cout << *sp.GetPointer() << std::endl;


    return 0;
}
