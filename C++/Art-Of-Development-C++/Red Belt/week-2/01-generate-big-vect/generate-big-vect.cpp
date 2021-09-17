#include <chrono>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace std::chrono;

/* FIRST VARIANT: */
vector<string> GenerateBigVector() {
    vector<string> result;

    auto start = steady_clock::now();

    for (int i = 0; i < 28'000; ++i) {
        result.push_back(to_string(i));
    }


    auto finish = steady_clock::now();
    cerr << "Cycle: " << duration_cast<milliseconds>(finish - start).count() << endl;

    return result;
}


/* SECOND VARIANT: (JUST EXAMPLE TO THINK)
vector<string> GenerateBigVector(vector<string> &result) {
    for (int i = 0; i < 28'000; ++i) {
        result.insert(begin(result), to_string(i));
    }
}
*/


int main() {
    auto start = steady_clock::now();
    cout << GenerateBigVector().size() << endl;
    auto finish = steady_clock::now();
    cerr << "Total: " << duration_cast<milliseconds>(finish - start).count() << endl;
}
