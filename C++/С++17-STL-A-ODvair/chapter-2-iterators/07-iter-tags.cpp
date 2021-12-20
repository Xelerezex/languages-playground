#include <iostream>
#include <vector>
#include <iterator>

void foo(std::bidirectional_iterator_tag t)
{
    puts("std::vector's iterators are indeed bidirectional...");
}

void bar(std::random_access_iterator_tag)
{
    puts("...and random-access, too!");
}

void bar(std::forward_iterator_tag)
{
    puts("forward_iterator_tag is not good a match");
}


int main()
{
    using It = std::vector<int>::iterator;
    foo(It::iterator_category{});
    bar(It::iterator_category{});
}
