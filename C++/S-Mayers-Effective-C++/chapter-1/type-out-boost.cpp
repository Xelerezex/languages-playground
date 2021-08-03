// Function typeid can not give to us fully right output
// Just remember it

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

class Widget {};

template<typename T>
void f(const T& param);

std::vector<Widget> createWec();

int main() {

    const auto vw = createWec();

    if(!vw.empty()) {
        f(&vw[0]);
    }

    return 0;
}


template<typename T>
void f(const T& param) {

    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    cout << "T     =  "
         << type_id_with_cvr<T>().pretty_name()
         << '\n';

    cout << "param =  "
         << type_id_with_cvr<decltype(param)>().pretty_name()
         << '\n';
}


std::vector<Widget> createWec() {
    Widget w;
    std::vector<Widget> vw(2);
    vw.push_back(w);
    vw.push_back(w);
    return vw;
}
