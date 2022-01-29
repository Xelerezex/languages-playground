#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

template <typename Iterator>
class IteratorRange {
    private:
        Iterator first, last;
    public:
        IteratorRange(Iterator f, Iterator l) :first(f), last(l) {}

        Iterator begin() const {
            return first;
        }

        Iterator end() const {
            return last;
        }
};



template <typename T>
size_t RangeSize(IteratorRange<T> r) {
    return r.end() - r.begin();
}


template <typename Container>
auto Head(Container& v, size_t top) {
    return IteratorRange {
        v.begin(), next(v.begin(), min(top, v.size()))
    };
}


int main() {
    const deque<int> v = {1, 2, 3, 4, 5};

    for (int x : Head(v, 3)) {
        cout << x << '\n';
    }
}
