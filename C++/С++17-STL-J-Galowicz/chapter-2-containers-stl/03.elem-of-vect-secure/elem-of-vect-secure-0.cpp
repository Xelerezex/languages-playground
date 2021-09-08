#include <iostream>
#include <vector>


template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l);

int main() {
    const size_t container_size {1000};
    std::vector<int> v (container_size, 123);

    std::cout << "Out of range element value: "
              << v[container_size + 10] << std::endl;
    try {
        std::cout << v.at(container_size + 10) << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << "Out of range access detected: "
                  << e.what() << '\n';
    }
}


//-------------FOR-VECTOR
template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l) {
    os << "[";
    bool first = true;

    for(const auto& i : l) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << i;
    }

    return os << "]";
}
