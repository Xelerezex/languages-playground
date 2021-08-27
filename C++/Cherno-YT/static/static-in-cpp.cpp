#include <iostream>
#include "static-in-cpp.h"

using namespace std;

/* TWO SITUATIONS:
*       static OUTSIDE the class -
*               The linkage of symbol that we declared to be static is going to be internal (visible only in unit where it defined)
*               meaning.
*
*       static INSIDE the class -
*               That static variable will share memory with all of the instance of class (for all n instance of class, will be ONE
*               static variable, not n copy of that variable, for each instance)
*/


// Static outside the class:

// Extern finds variables in other files, if they are static
// Only way to get static from it's file - with extern
extern int s_Variable;

static void Foo() {

}

int main() {

    cout << s_Variable << endl;



    return 0;
}
