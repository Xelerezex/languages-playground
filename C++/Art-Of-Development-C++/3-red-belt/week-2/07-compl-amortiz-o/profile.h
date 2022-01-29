#pragma once

#include <chrono>
#include <string>
#include <iostream>
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
