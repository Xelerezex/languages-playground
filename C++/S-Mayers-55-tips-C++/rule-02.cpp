// Rule #2:
// Compiler better than preprocessor.

#include <iostream>

// This is better:
const double AspectRatio = 1.653;
// than this:
#define ASPECT_RATIO 1.653

class GamePlayer
{
    private:
        enum { NumTurns = 5};   // Trick, like const, but can't get addres of 5 (like #define)

        int scores[NumTurns];
};

int f(int i)
{
    return i + 0;
}

// Never this:
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
// Better do this:
template <typename T>
inline void callWithMax(const T &a, const T &b)
{
    f(a > b ? a : b);
}

int main()
{
    {
        int a = 5, b = 0;
        CALL_WITH_MAX(++a, b);
        CALL_WITH_MAX(++a, b+10);

        std::cout << a << " " << b << std::endl;
    }
    {
        int a = 5, b = 0;
        callWithMax(++a, b);
        callWithMax(++a, b+10);

        std::cout << a << " " << b << std::endl;
    }
}
