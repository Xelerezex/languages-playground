#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename Iterator, typename Item>
auto my_binary_search(Iterator begin_it, Iterator end_it, Item item) {

    while (begin_it < end_it) {

        Iterator middle = next(begin_it, (distance(begin_it, end_it) / 2));

        cout << *middle << endl;

        if (item == *middle) {
            return middle;
        }

        if (item < *middle) {
            end_it = middle - 1;
        } else {
            begin_it = middle + 1;
        }
    }

    return end_it;
}

int main() {
    vector<int> list(100'000);
    iota(begin(list), end(list), 1);
    int element = 50'002;

    auto found_elem = my_binary_search(begin(list), end(list), element);

    if (found_elem != end(list)){
        cout << "FOUNT IT:\n\t"
             << *found_elem << endl;
    } else {
        cout << "NOT FOUND!" << endl;
    }
}
