#include <iostream>

using namespace std;

/* This turns
*   class Singleton {
*       public:
*           static Singleton& Get() {return *s_Instance;}
*
*           void Hello () {}
*       private:
*           static Singleton* s_Instance;
*   };
*
*   Singleton* Singleton::s_Instance = nullptr;
* Into this:
*/

class Singleton {
    public:
        static Singleton& Get() {
            static Singleton* s_Instance;
            return *s_Instance;
        }

        void Hello () {}
};


void Function() {
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}


int main() {
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();

    Singleton::Get().Hello();

    return 0;
}
