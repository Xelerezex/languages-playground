#include <iostream>
#include "profile.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);   // FIRSTLY THAT COMMAND. ONLY AFTER IT - cout
    cin.tie(nullptr);                   // NO BUFFER DUMP

    {
        LOG_DURATION("endl");

        for (int i = 0; i < 150'000; ++i) {
            int x;
            cin >> x;
            cout << x << endl;
        }
    }
    {
        LOG_DURATION("\'\\n\'");



        for (int i = 0; i < 150'000; ++i) {
            int x;
            cin >> x;
            cout << x << '\n';
        }
    }
}
