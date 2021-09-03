// SOLVING SAME PROBLEM WHEN THERE IS NO C++17^

#include <vector>
#include <string>

template <typename T>
class addable {
    private:
        T val;
    public:
        addable(T v) : val{v} {}

        template<typename U>
        std::enable_if_t<!std::is_same<T, std::vector<U>>::value, T>
        add(U x) const { return val + x; }


        template<typename U>
        std::enable_if_t<std::is_same<T, std::vector<U>>::value, std::vector<U>>
        add(U x) const {
            auto copy (val);
            for (auto &n : copy) {
                n += x;
            }
            return copy;
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
}
