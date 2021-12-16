#include <vector>
#include <string>
#include <deque>

template <typename T>
class addable {
    private:
        T val;
    public:
        addable(T v) : val{v} {}

        template<typename U>
        T add(U x) const {
            if constexpr (std::is_same_v<T, std::vector<U>>) {  // CHECKS, IS VARIABLE HAS SAME TYPE
                auto copy (val);
                for (auto &n : copy) {
                    n += x;
                }
                return copy;

            } else if constexpr (std::is_same_v<T, std::deque<U>>) {  // BRANCHING
                auto copy (val);
                for (auto &n : copy) {
                    n += x;
                }
                return copy;
            } else {
                return val + x;
            }
        }
};

int main() {
    addable<int>{1}.add(2);
    addable<float>{1.0}.add(2);
    addable<std::string>{"aa"}.add("bb");

    std::vector<int> v {1, 2, 3};
    addable<std::vector<int>>{v}.add(10);

    std::vector<std::string> sv {"a", "b", "c"};
    addable<std::vector<std::string>>{sv}.add(std::string{"z"});

    std::deque<std::string> sd {"a", "b", "c"};
    addable<std::deque<std::string>>{sd}.add(std::string{"z"});
}
