#include "tools.h"


int main()
{
    std::vector<bool> vec {
        true, false, true, false, true, false, false, true, true, false
    };
    vec.reserve(60);

    std::vector<bool> vb = {true, false, true, false};
    vb[3].flip();

    assert(vb[3] == true);

    auto ref = vb[0];
    assert((!std::is_same_v<decltype(ref), bool>));
    assert(sizeof vb[0] > sizeof (bool));

    if (sizeof std::as_const(vb)[0] == sizeof(bool))
    {
        puts("Your library vendor is libstdc++ or VS");
    }
    else
    {
        puts("Your library vendor is libc++");
    }
}
