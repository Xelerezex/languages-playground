#include <utility>
#include <tuple>

int main() {
    // No need in <int, const char*....>
    std::pair  my_pair   (123, "abc");
    std::tuple my_tuple  (123, "abc", 3.0);
}
