#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>

using namespace std;

class Date {
public:
    // Constructors:
    Date(const int& y, const int& m, const int& d) :
        Year(y),
        Month([m] {
            if (m > 12 || m < 1) {
                throw logic_error("Month value is invalid: " + to_string(m));
            } else {
                return m;
            }
        }() ),
        Day([d] {
            if (d > 31 || d < 1) {
                throw logic_error("Day value is invalid: " + to_string(d));
            } else {
                return d;
            }
        }() ) {/*cout << "Works Well" << endl;*/}

    // Getters:
    int GetYear() const {
        return Year;
    }
    int GetMonth() const {
        return Month;
    }
    int GetDay() const {
        return Day;
    }
private:
    const int Year;
    const int Month;
    const int Day;
};

Date ParseDate(const string& date) {
    istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
      throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}


ostream& operator<<(ostream& stream, const Date& date) {
    return  stream << setw(4) << setfill('0') << date.GetYear() <<
               "-" << setw(2) << setfill('0') << date.GetMonth() <<
               "-" << setw(2) << setfill('0') << date.GetDay();
}


bool operator<(const Date& lhs, const Date& rhs) {
    return  vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}
        <   vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        ==   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator!=(const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        !=   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
int main () {
    Date date1 = ParseDate("2020-12-31");
    Date date2 = ParseDate("2020-12-30");

    cout << ((date1 < date2) ? "true" : "false") << endl;
    cout << ((date1 == date2) ? "true" : "false") << endl;
    cout << ((date1 != date2) ? "true" : "false") << endl;

}
