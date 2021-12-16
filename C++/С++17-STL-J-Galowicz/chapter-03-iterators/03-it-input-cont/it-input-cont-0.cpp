#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <deque>

using namespace std;

int main() {
    istream_iterator<int> it_cin {cin};
    istream_iterator<int> end_cin;

    deque<int> d;
    copy(it_cin, end_cin, back_inserter(d));

    istringstream sstr {"123 456 789"};

    auto deque_middle (next(begin(d),
                            static_cast<int>(d.size() / 2)));

    copy(istream_iterator<int>{sstr}, {}, inserter(d, deque_middle));

    initializer_list<int> il2 {-1, -2, -3};
    copy(begin(il2), begin(il2), front_inserter(d));


    copy(begin(d), begin(d), ostream_iterator<int>{cout, ", "});
    cout << '\n';
}
