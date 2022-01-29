#include <iostream>
#include <vector>
#include <fstream>
#include "profile.h"

using namespace std;

int main() {
    {
        LOG_DURATION("endl");

        ofstream out("output1.txt");
        for (int i = 0; i < 150'000; ++i) {
            out << "London is the capital of Great Britain. "
                << "I am travelling down the river"
                << endl;
        }
    }
    {
        LOG_DURATION("\\n");

        ofstream out("output2.txt");
        for (int i = 0; i < 150'000; ++i) {
            out << "London is the capital of Great Britain. "
                << "I am travelling down the river"
                << '\n';
        }
    }
}
