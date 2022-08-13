#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>


int main()
{

    auto startTime = std::chrono::high_resolution_clock::now();
    auto stopTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);

    std::cout << "Finished in: "  << duration.count() << "ms" << std::endl;

    return 0;
}
