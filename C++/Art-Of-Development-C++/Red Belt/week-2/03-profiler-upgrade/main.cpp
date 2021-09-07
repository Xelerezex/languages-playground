#include <chrono>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;


class LogDuration {
    public:
        explicit  LogDuration(const string &msg = "")
        : message(msg + ": ")
        , start(steady_clock::now()) {}

        ~LogDuration() {
            auto finish   = steady_clock::now();
            auto duration = finish - start;
            cerr << message << duration_cast<milliseconds>(duration).count()
                 << " ms" << endl;
        }
    private:
        string message;
        steady_clock::time_point start;
};

#define UNIQ_ID_IMPL(_lineno_) _a_local_var_##_lineno_
#define UNIQ_ID(_lineno_) UNIQ_ID_IMPL(_lineno_)

#define LOG_DURATION(_message_)   \
    LogDuration UNIQ_ID(__LINE__) {_message_};


int main() {
    LOG_DURATION("Total");

    ifstream in("input.txt");
    int element_count;
    in >> element_count;

    set<int> elements;

    {
        LOG_DURATION("Input");
        for (int i = 0; i < element_count; ++i) {
            int x;
            in >> x;
            elements.insert(x);
        }
    }
    int query_count;
    in >> query_count;

    int total_found = 0;
    {
        LOG_DURATION("Queries proccesing");
        for (int i = 0; i < query_count; ++i) {
            int x;
            in >> x;
            if (elements.find(x) != elements.end()) {
                ++total_found;
            }
        }
    }

    cout << total_found << endl;

    return 0;
}
