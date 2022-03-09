#include "tools.h"

void ProcessNumberOne(const std::vector<int> s)
{}

void ProcessNumberTwo(const std::vector<int> s)
{}

void ProcessNumberThree(const std::vector<int> s)
{}

std::vector<int> Sorted(std::vector<int> data)
{
    std::sort(begin(data), end(data));
    return data;
}


int main()
{
    const std::vector<int> sorted_numbers = [] /*()*/ {
        std::vector<int> data = Sorted({5, 4, 2, 1, 5, 1, 3, 4, 5});
        auto it = std::unique(begin(data), end(data));
        data.erase(it, end(data));
        return data;
    } ();

    for (int x : sorted_numbers)
    {
        std::cout << x << ' ';
    }

    ProcessNumberOne(sorted_numbers);
    ProcessNumberTwo(sorted_numbers);
    ProcessNumberThree(sorted_numbers);

}
