#include "tools.h"
#include "json.h"
#include "xml.h"

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

vector<Spending> LoadFromJson(istream& input)
{
    Json::Document doc = Json::Load(input);
    vector<Spending> output;

    for (const auto &pair : doc.GetRoot().AsArray())
    {
        output.push_back(Spending{
            pair.AsMap().at("category").AsString(),
            pair.AsMap().at("amount").AsInt()
        });
    }

    return output;
}

vector<Spending> LoadFromXml(istream& input)
{
    Xml::Document doc = Xml::Load(input);
    vector<Spending> output;

    for (const auto &child : doc.GetRoot().Children())
    {
        output.push_back(Spending{
            child.AttributeValue<string>("category"),
            child.AttributeValue<int>("amount")
        });
    }
    return output;
}

int main()
{
/*    const vector<Spending> spendings = {
        {"food", 2500},
        {"transport", 1150},
        {"restaurants", 5780},
        {"clothes", 7500},
        {"travel", 23740},
        {"sport", 12000}
    };*/

    istringstream json_input(R"([
        {"amount": 2500, "category": "food"},
        {"amount": 1150, "category": "transport"},
        {"amount": 5780, "category": "restaurants"},
        {"amount": 7500, "category": "clothes"},
        {"amount": 23740, "category": "travel"},
        {"amount": 12000, "category": "sport"}
    ])");

    // ifstream json_input("spendings.json");
    const auto spendings = LoadFromJson(json_input);

    cout << "Total "
         << CalculateTotalSpendings(spendings) << endl;

    cout << "Most expensive "
         << MostExpensiveCategory(spendings) << endl;
}
