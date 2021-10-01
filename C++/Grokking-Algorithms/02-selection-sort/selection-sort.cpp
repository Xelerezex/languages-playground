#include <iostream>
#include <vector>
#include <random>
#include "profile.h"

template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l);

template <typename firstIt>
firstIt FindSmallest(firstIt beginF, firstIt endF);

template <typename T, typename F>
void SelectionSort(std::vector<T> &first, std::vector<F> &second);

template <typename firstIt>
firstIt FindSmallest(firstIt beginF, firstIt endF) {
    firstIt iter_to_pop = beginF;
    for (auto iter = beginF; iter != endF; ++iter) {
        if (*iter_to_pop > *iter) {
            iter_to_pop = iter;
        }
    }
    return iter_to_pop;
}


template <typename T, typename F>
void SelectionSort(std::vector<T> &first, std::vector<F> &second) {
    for (auto& item : second) {
        auto er = FindSmallest(first.begin(), first.end());
        first.erase(er);
        item = *er;
    }


}

int main() {
    std::vector<int> first(50'000);
    std::vector<int> second(50'000);


    {
        LOG_DURATION("Vector with random nubers O(n)");         // With 50'000 element: 782 ms
        for (auto& item : first) {
            std::random_device rd;
            std::mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна случайным стартовым число
            item = mersenne() % 1000;
        }
    }


    {
        LOG_DURATION("Selecetion SOrt with O(n^2)");            // With 50'000 element: 12019 ms
        SelectionSort(first, second);
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
