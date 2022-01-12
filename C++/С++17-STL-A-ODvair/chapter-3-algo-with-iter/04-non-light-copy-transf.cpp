#include "tools.h"

template<class InIt, class OutIt, class Unary>
OutIt my_transform(InIt first1, InIt last1, OutIt destination, Unary op)
{
    while (first1 != last1)
    {
        *destination = op(*first1);
        ++first1;
        ++destination;
    }
    return destination;
}

template<class InIt1, class InIt2, class OutIt, class Unary>
OutIt my_transform(InIt1 first1, InIt1 last1, InIt2 first2, OutIt destination, Unary op)
{
    while (first1 != last1)
    {
        *destination = op(*first1, *first2);
        ++first1;
        ++destination;
    }
    return destination;
}

int main()
{
    {
        std::vector<const char *> input = {"hello", "world"};
        std::vector<std::string> output(2);

        std::copy(input.begin(), input.end(), output.begin());

        assert(output[0] == "hello");
        assert(output[1] == "world");
    }
    {
        std::vector<std::string> input = {"hello", "world"};
        std::vector<std::string> output(2);

        my_transform(
            input.begin(),
            input.end(),
            output.begin(),
            [] (std::string s) {
                my_transform(s.begin(), s.end(), s.begin(), ::toupper);
                return s;
            }
        );

        ASSERT_EQUAL(input[0], "hello");
        ASSERT_EQUAL(output[0], "HELLO");
    }
    {
        std::vector<std::string> input = {"hello", "world"};
        std::vector<std::string> output(2);

        my_transform(
            input.begin(),
            input.end(),
            output.begin(),
            std::move<std::string&>
        );

/*        ASSERT_EQUAL(input[0], "");           // ???
        ASSERT_EQUAL(output[0], "HELLO");*/
    }
}
