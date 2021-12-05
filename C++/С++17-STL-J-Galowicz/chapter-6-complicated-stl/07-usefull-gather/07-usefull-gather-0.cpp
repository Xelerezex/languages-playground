#include <functional>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename It, typename F>
pair<It, It> gather (It first, It last, It gather_pos, F predicate)
{
    return {
        stable_partition(first, gather_pos, not_fn(predicate)),
        stable_partition(gather_pos, last, predicate)
    };
}

template <typename It, typename F>
void gather_sort (It first, It last, It gather_pos, F predicate)
{
    auto inv_comp_func (
        [&] (const auto &...ps) {
            return !comp_func(ps...);
        }
    );
    stable_sort(first, gather_pos, inv_comp_func);
    stable_sort(gather_pos, last, comp_func);
}

int main()
{
    auto is_a (
        [] (char c) {
            return c == 'a';
        }
    );

    string a {"a_a_a_a_a_a_a_a_a_a"}
    auto middle (begin(a) + a.size() / 2);

    gather(begin(a), end(a), middle, is_a);
    cout << a << '\n';

    gather(begin(a), end(a), begin(a), is_a);
    cout << a << '\n';

    gather(begin(a), end(a), end(a), is_a);
    cout << a << '\n';
}
