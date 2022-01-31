#include "tools.h"

// De facto Hash funtion
int GetIndex(size_t n)
{
    if (n == 10) return 0;
    if (n == 50) return 1;
    if (n == 100) return 2;
    if (n == 200) return 3;
    if (n == 500) return 4;
    if (n == 1000) return 5;
    if (n == 2000) return 6;
    if (n == 5000) return 7;
}

int main()
{
    std::vector<size_t> cash(8);
    size_t nominal;
    while (std::cin >> nominal)
    {
        cash[GetIndex(nominal)]++;
    }

    static std::array<int, 8> names = {
        10, 50, 100, 200, 500, 1000, 2000, 5000
    };

    for (size_t i = 0; i < cash.size(); ++i)
    {
        if (cash[i] != 0)
        {
            std::cout << names[i] << " - " << cash[i] << std::endl;
        }
    }
}
