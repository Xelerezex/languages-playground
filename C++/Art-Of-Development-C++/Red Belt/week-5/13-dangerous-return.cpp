#include <fstream>

using namespace std;

pair<ifstream, ofstream> MakeStreams1(const string& prefix) {
    ifstream input(prefix + ".in");
    ofstream output(prefix + ".out");
    return {move(input), move(output)};
}


pair<ifstream, ofstream> MakeStreams2(const string& prefix) {

    return {ifstream(prefix + ".in"), ofstream(prefix + ".out")};
}

pair<ifstream, ofstream> MakeInputStream(const string& prefix) {
    auto streams = MakeStreams2(prefix);
    return move(streams.first);
}

int main() {

    return 0;
}
