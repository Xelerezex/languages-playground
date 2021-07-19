#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;


pair<string, string> SplitTwoStrict(string s, string delimiter) {
    const size_t pos = s.find(delimiter);
    if (pos == s.npos) {
      return {s, ""};
    } else {
      return {s.substr(0, pos), s.substr(pos + delimiter.length())};
    }
}

pair<string, string> SplitTwo(string s, string delimiter) {
    const auto [lhs, rhs] = SplitTwoStrict(s, delimiter);
    return {lhs, rhs};
}

string ReadToken(string& s, string delimiter = " ") {
    const auto [lhs, rhs] = SplitTwo(s, delimiter);
    s = rhs;
    return lhs;
}

int ConvertToInt(string str) {
    size_t pos;
    const int result = stoi(string(str), &pos);

    // Check, that in str no Character
    if (pos != str.length()) {
      stringstream error;
      error << "string " << str << " contains " << (str.length() - pos) << " trailing chars";
      throw invalid_argument(error.str());
    }
    return result;
}

class Date {
    public:
        static Date FromString(string str) {
            const int year = ConvertToInt(ReadToken(str, "-"));
            const int month = ConvertToInt(ReadToken(str, "-"));
            const int day = ConvertToInt(str);
            return {year, month, day};
      }

  // Weird legacy, can't wait for chrono::year_month_day
    time_t AsTimestamp() const {
        tm t;
        t.tm_sec  = 0;
        t.tm_min  = 0;
        t.tm_hour = 0;
        t.tm_mday = day_;
        t.tm_mon  = month_ - 1;
        t.tm_year = year_ - 1900;
        t.tm_isdst = 0;
        return mktime(&t);
    }

    int getDay() const {
        return day_;
    }

    int getMonth() const {
        return month_;
    }

    int getYear() const {
        return year_;
    }

    private:
        int year_;
        int month_;
        int day_;

        Date(int year, int month, int day)
            : year_(year), month_(month), day_(day) {}
};


ostream& operator << (ostream& out, const Date& date){
    return out  << setw(4) << setfill('0')
                << date.getYear() << "-"
                << setw(2) << setfill('0')
                << date.getMonth()
                << "-" << date.getDay();
}

int main() {
    Date date_from = Date::FromString("1970-01-100");

    return 0;
}
