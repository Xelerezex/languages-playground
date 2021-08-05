#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <set>


template <class T>
std::ostream& operator << (std::ostream& os, const std::set  <T>& s);

template <class K,  class V>
std::ostream& operator << (std::ostream& os, const std::map  <K, V>& m);

template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l);

template <class F, class S>
std::ostream& operator << (std::ostream& os, const std::pair <F, S>& fs);

template <class T>
std::ostream& operator << (std::ostream& os, const std::stack <T>& t);

//------------------------------OUTPUT-OPERATOR-FOR-CONTAINERS----------------------------------//
//-------------FOR-SET
template <class T>
std::ostream& operator << (std::ostream& os, const std::set <T>& s) {
    os << "{";
    bool first = true;

    for(const auto& x : s) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << x;
    }

    return os << "}";
}


//-------------FOR-MAP
template <class K, class V>
std::ostream& operator << (std::ostream& os,const std::map <K, V>& m) {
    os <<"{";
    bool first = true;

    for(const auto& kv : m) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << kv.first << ": " << kv.second;

    }
    return os <<"}";
}


//-------------FOR-VECTOR
template <class L>
std::ostream& operator << (std::ostream& os, const std::vector <L>& l) {
    os << "[";
    bool first = true;

    for(const auto& i : l) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << i;
    }

    return os << "]" << "\tvector\tsize:" << l.size();
}

//-------------FOR-PAIR
template <class F, class S>
std::ostream& operator << (std::ostream& os, const std::pair <F, S>& fs) {
    return os << "<" << fs.first << " : " << fs.second << ">";
}

//-------------FOR-STACK
template <class T>
std::ostream& operator << (std::ostream& os, const std::stack <T>& s) {
    std::stack<T> t = s;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!--------------------EVALUATE
    while (!t.empty()) {
        os << t.top()->Get() << ' ';
        t.pop();
    }
    return os << "";
}
