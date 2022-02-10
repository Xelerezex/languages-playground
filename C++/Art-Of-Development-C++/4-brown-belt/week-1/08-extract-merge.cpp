#include "tools.h"

struct  NCString : public std::string
{
    using std::string::string;
    NCString(const NCString&) = default;
    NCString(NCString&&) = default;
};

int main()
{
    std::set<NCString> ss;
    ss.insert("Aaa");
    ss.insert("Bbb");
    ss.insert("Ccc");

    std::cerr << ss << std::endl;

    auto it = ss.begin();
    auto node = ss.extract(it);
    std::string& temp = node.value();
    temp[0] = tolower(temp[0]);
    ss.insert(move(node));

    std::cerr << ss << std::endl;

    std::set<NCString> ss2;
    ss2.insert("Xxx");
    ss2.insert("Yyy");
    ss2.insert("yyy");

    std::cerr << ss2 << std::endl;

    ss.merge(ss2);

    std::cerr << ss << std::endl;
    std::cerr << ss2 << std::endl;
}
