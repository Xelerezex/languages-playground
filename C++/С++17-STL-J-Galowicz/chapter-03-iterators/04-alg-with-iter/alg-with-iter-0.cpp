#include <iostream>

class fibit {
    public:
        fibit() = default;
        explicit fibit(size_t index_) : index{index_}
        {}

        size_t operator*() const { return b; }

        fibit& operator++() {
            const size_t old_b {b};
            b += a;
            a = old_b;
            ++index;
            return *this;
        }

        bool operator!=(const fibit &o) const { return index != o.index; }
    private:
        size_t index {0};
        size_t a {0};
        size_t b {1};
};

class fib_range {
    private:
        size_t end_n;
    public:
        fib_range(size_t end_n_) : end_n {end_n_}
        {}

        fibit begin() const { return fibit{}; }
        fibit end()   const { return fibit{end_n}; }
};

int main() {
    for (size_t i : fib_range(10)) {
        std::cout << i << ", ";
    }
    std::cout << '\n';
}
