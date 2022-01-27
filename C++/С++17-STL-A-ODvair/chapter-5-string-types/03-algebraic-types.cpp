#include "tools.h"

enum class Color
{
    RED = 1,
    BLACK = 2,
};
enum class Size
{
    SMALL = 1,
    MEDIUM = 2,
    LARGE = 3,
};

using sixtype  = std::pair<Color, Size>;
using fivetype = std::variant<Color, Size>;

int main()
{
    sixtype six = {Color::BLACK, Size::LARGE};
}
