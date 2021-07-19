#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;


template <class TimerFunc>
void funcTimer(TimerFunc func){

    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();

    cerr << duration_cast<microseconds>(stop - start).count() << " microseconds"
         << " (" << duration_cast<seconds>(stop - start).count() << " seconds)!" << endl;
}

void Test(){
    vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    sort(values.begin(), values.end());
}

int main(){

    funcTimer(Test);

    return 0;
}
