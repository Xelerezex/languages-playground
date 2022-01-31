#include "tools.h"


int main()
{
    {
        auto capture = [] (auto &p) {
            using T = std::decay_t<decltype(p)>;
            return std::make_shared<T>(std::move(p));
        };

        std::promise<int> p;

        std::function<void()> f = [sp = capture(p)]() {
            sp -> set_value(42);
        };
    }
}
