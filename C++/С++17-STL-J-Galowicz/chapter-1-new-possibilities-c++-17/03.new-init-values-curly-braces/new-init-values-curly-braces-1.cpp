int main() {
    auto v {1};             // int
    auto w {1, 2};          // error


    auto x = {1};           // std::initializer_list<int>
    auto x = {1, 2};        // std::initializer_list<int>
    auto x = {1, 2, 3.0};   // error
}
