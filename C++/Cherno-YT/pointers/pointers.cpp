#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

int main () {

    int var = 8;        // Created in Stack
    int* ptr = &var;
    *ptr = 10;
    LOG(*ptr);

    char* buffer = new char[8];     // Allocates 8 bytes of memory. Created on Heap
    memset(buffer, 0, 8);

    delete[] buffer;

    return 0;
}
