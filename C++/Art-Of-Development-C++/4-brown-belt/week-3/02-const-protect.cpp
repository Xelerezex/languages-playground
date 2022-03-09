#include "tools.h"

template<typename T>
void CopyIfNotEqual(const std::vector<T> &src, std::vector<T> &dst, T value)
{
    std::remove_copy(src.begin(), src.end(), back_inserter(dst), value);
}

void TestCopyIfNotEqual()
{
    std::vector<int> values = {
        1, 3, 8, 3, 2, 4, 8, 0, 9, 8, 6
    };

    std::vector<int> dest;
    CopyIfNotEqual(values, dest, 8);

    std::vector<int> expected = {
        1, 3, 3, 2, 4, 0, 9, 6
    };

    ASSERT_EQUAL(dest, expected);
}

int main()
{
    {
        TestRunner tr;
        RUN_TEST(tr, TestCopyIfNotEqual);
    }
    {
        int value = 4;
        auto increase = [value] (int x) /*without: *//*mutable*/ /*will be an error*/{
            return value += x;
        };

        std::cout << increase(6) << std::endl;
        std::cout << increase(6) << std::endl;
    }
}
