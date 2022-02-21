#include "tools.h"

using namespace std;

struct Spending
{
    string category;
    int amount;
};

int CalculateTotalSpendings(const vector<Spending>& spendings)
{
    int result = 0;
    for (const Spending& s : spendings)
    {
        result += s.amount;
    }

    return result;
}

string MostExpensiveCategory(const vector<Spending>& spendings)
{
    auto compare_by_amount = [] (const Spending& lhs, const Spending& rhs)
    {
        return lhs.amount < rhs.amount;
    };

    return max_element(begin(spendings), end(spendings), compare_by_amount) -> category;
}

int main()
{
    const vector<Spending> spendings = {
        {"food", 2500},
        {"transport", 1150},
        {"restaurants", 5780},
        {"clothes", 7500},
        {"travel", 23740},
        {"sport", 12000}
    };

    cout << "Total "
         << CalculateTotalSpendings(spendings) << endl;
    cout << "Most expensive "
         << MostExpensiveCategory(spendings) << endl;
}
