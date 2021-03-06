#include <map>
#include <string>
using namespace std;

// Возвращает пустую строку, если имя неизвестно
string FindNameByYear(const map<int, string>& names, int year) {
    auto iter_after = names.upper_bound(year);
    string name;
    if (iter_after != names.begin()) {
        name = (--iter_after)->second;
    }
    return name;
}

class Person {
public:
    // call for temporary: move -> move
    // else: copy -> move
    void ChangeFirstName(int year, string first_name) {
        first_names[year] = move(first_name);
    }
    void ChangeLastName(int year, string last_name) {
        last_names[year] = move(last_name);
    }
    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
    Person person;
    person.ChangeFirstName(2018, string(10, 'a'));
    return 0;
}
