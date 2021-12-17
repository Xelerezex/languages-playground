#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main()
{
    path p {"testdir/foobar.txt"};

    cout << "current_path       : " << current_path()
         << "\nabsolute_path    : " << absolute(p)
         << "\nsystem_complete  : " << system_complete(p)
         << "\ncanonical(p)     : " << canonical(p)
         << '\n';

    cout << path{"testdir"} / "foobar.txt" << '\n';

    cout << "canonical testdir : "
         << canonical("foobar.txt", current_path() / "testdir")
         << "\ncanonical testdir 2 : "
         << canonical(p, current_path() / "testdir/..")
         << '\n';

    cout << "equvalance: "
         << equevalent("testdir/foobar.txt", "testdir/../testdir/foobar.txt")
         << '\n';
}
