#include "tools.h"

template <typename T>
class LazyValue
{
    public:
        explicit LazyValue(std::function<T()> init) : init_(std::move(init))
        {
        }

        bool HasValue() const
        {
            return value_.has_value();
        }

        const T& Get() const
        {
            if (std::lock_guard g(m); !value_)
            {
                value_ = init_();
            }
            return *value_;
        }

    private:
        std::function<T()> init_;
        mutable std::optional<T> value_;
        mutable std::mutex m;
};

int main()
{
    LazyValue<std::map<std::string, int>> city_population(
        [&] {
            return std::map<std::string, int>{
                {"Moscow", 11514330},
                {"Saint Petersburg", 4848742},
                {"Novosibirsk", 1498921},
                {"Ekaterinburg", 1377738},
                {"Nijni Novgorod", 1250615},
                {"Kazan", 1216965},
                {"Samara", 1164900},
                {"Omsk", 1154000},
                {"Chelabinsk", 1130273},
                {"Rostov-na-Dony", 1091544},
                {"Ufa", 1062300},
                {"Volgograd", 1021244},
                {"Tula", 1157909},
                {"Saratov", 1277309},
            };
        }
    );

    auto kernel = [&] {
        return city_population.Get().at("Tula");
    };

    std::vector<std::future<int>> ts;
    for (size_t i = 0; i < 25; ++i)
    {
        ts.push_back(std::async(kernel));
    }

    for (auto &t : ts)
    {
        t.get();
    }

    const std::string saratov = "Saratov";
    std::cout << saratov << ' ' << city_population.Get().at(saratov) << '\n';
}
