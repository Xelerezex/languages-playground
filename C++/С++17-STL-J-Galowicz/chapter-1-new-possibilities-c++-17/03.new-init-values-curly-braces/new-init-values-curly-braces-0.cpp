#include <vector>

int main() {
    // Identical ways of initialization:
    int x1 = 1;
    int x2 {1};
    int x3 (1);

    // Here is warning:
    // Just initialization:
    std::vector<int> v1 {1, 2, 3};
    std::vector<int> v2 = {1, 2, 3};
    // std::vector Constructor. Will be: {6, 6, 6, 6, 6, 6}
    std::vector<int> v3 (5, 6);

}
