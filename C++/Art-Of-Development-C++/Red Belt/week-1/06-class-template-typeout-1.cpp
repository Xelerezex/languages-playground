#include <iostream>
#include <vector>

using namespace std;

template <typename Iterator>
struct IteratorRange {
    Iterator first, last;

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }
};


template <typename T>
IteratorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t top) {
    return {
        v.begin(), next(v.begin(), min(top, v.size()))
    };
}


template <typename T>
size_t RangeSize(IteratorRange<T> r) {
    return r.end() - r.begin();
}

template<typename Iterator>
IteratorRange<Iterator> MakeRange(
    Iterator begin, Iterator end
) {
    return IteratorRange<Iterator>{begin, end};
}


int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    for (int& x : Head(v, 3)) {
        ++x;
    }

    for (int& x : v) {
        cout << x << ' ';
    }
    cout << endl;

    auto second_half = MakeRange (
        v.begin() + v.size() / 2, v.end()
    );

   for (int& x : second_half) {
        cout << x << ' ';
    }

    return 0;
}
