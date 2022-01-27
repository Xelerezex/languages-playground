#include "tools.h"

using Author = std::pair<std::string, std::string>;

int main()
{
    {
        std::vector<Author> authors
        {
            {"Fyordor", "Dostoevsky"},
            {"Sylvia", "Plath"},
            {"Vladimir", "Nabokov"},
            {"Douglas", "Hofstadter"},
        };

        std::sort(
            authors.begin(),
            authors.end(),
            [] (auto&& a, auto&& b)
            {
                return std::tie(a.first, a.second) < std::tie(b.first, b.second);
            }
        );

        ASSERT_EQUAL(authors[0], (Author{"Douglas", "Hofstadter"}));

        std::sort(
            authors.begin(),
            authors.end(),
            [] (auto&& a, auto&& b)
            {
                return std::tie(a.second, a.first) < std::tie(b.second, b.first);
            }
        );
        ASSERT_EQUAL(authors[0], (Author{"Fyordor", "Dostoevsky"}));
    }
    {
        std::string s;
        int i;

        std::tie(s, i) = std::make_tuple("hello", 42);
    }
    {
        auto [i, j, k] = std::tuple{1, 2, 3};

        auto t1 = make_tuple(i, std::ref(j), k);
        static_assert(std::is_same_v<decltype(t1), std::tuple<int, int&, int>>);

        auto t2 = make_tuple(i, std::ref(j), k);
        static_assert(
            std::is_same_v<
                decltype(t2),
                std::tuple<int, std::reference_wrapper<int>, int>
            >
        );
    }
}
