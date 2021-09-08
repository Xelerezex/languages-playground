#include <iostream>
#include <vector>
#include <algorithm>


template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l);


template <typename T>
void quick_remove_at(std::vector<T> &v, std::size_t idx);


template <typename T>
void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it);


int main() {
    std::vector<int> v {123, 456, 789, 100, 200};

    quick_remove_at(v, 2);

    std::cout << v << std::endl;

    quick_remove_at(v, std::find(std::begin(v), std::end(v), 123));

    std::cout << v << std::endl;
}


template <typename T>
void quick_remove_at(std::vector<T> &v, std::size_t idx) {
    if (idx < v.size()) {
        v[idx] = std::move(v.back());
        v.pop_back();
    }
}

template <typename T>
void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it) {
    if (it != std::end(v)) {
        *it = std::move(v.back());
        v.pop_back();
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
