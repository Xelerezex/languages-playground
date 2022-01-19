#include "tools.h"

int main()
{
    {
        std::array<char, 3> arr {42, 43, 44};

        for (const auto i : arr)
        {
            std::cerr << i << std::endl;
        }
    }
    {
        std::string c_style[4] {
            "the", "quick", "brown", "fox"
        };
        ASSERT_EQUAL(c_style[2], "brown");
        ASSERT_EQUAL(std::size(c_style), 4);
        ASSERT_EQUAL(std::distance(std::begin(c_style), std::end(c_style)), 4u);

        std::string other[4];
        std::copy(std::begin(c_style), std::end(c_style), std::begin(other));

        using std::swap;
        swap(c_style, other);

        ASSERT(c_style != other);
        ASSERT(
            std::equal(
                c_style, c_style + 4, other, other + 4
            )
        );
        ASSERT(
            ! std::lexicographical_compare(
                c_style, c_style + 4, other, other + 4
            )
        );
    }
    {
        std::array<std::string, 4> arr {{
            "the", "quick", "brown", "fox"
        }};

        ASSERT_EQUAL(arr[2], "brown");
        ASSERT_EQUAL(std::size(arr), 4);
        ASSERT_EQUAL(std::distance(std::begin(arr), std::end(arr)), 4u);

        std::array<std::string, 4> other;
        other = arr;

        using std::swap;
        swap(arr, other);

        ASSERT(&arr != &other);
        ASSERT(arr == other);
        ASSERT(arr >= other);
    }
}
