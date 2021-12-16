#include <iostream>
#include <set>

// FUNCTION THAT INSERTS & THROW BOOL IF ALL INSERT SUCCESSFULL

template <typename T, typename ... Ts>
bool insert_all(T &set, Ts ... ts) {
    return (set.insert(ts).second && ...);
}

int main() {
    std::set<int> my_set {1, 2, 3};

    std::cout << insert_all(my_set, 4, 5, 6) << std::endl;
    std::cout << insert_all(my_set, 7, 8, 2) << std::endl;
}
