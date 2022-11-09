// Thread for this code testing:
// https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom#3279550

#include <iostream>
#include <algorithm>

class wrapper
{
public:
    // Default constructor
    wrapper (size_t size = 0)
        : m_sSize{size}
        , m_pArray{m_sSize ? new int[m_sSize]() : nullptr}
    {
        std::cerr << "Called Default constructor for object: " << this << std::endl;
    }

    // Copy constructor
    wrapper (const wrapper& other)
        : m_sSize{other.m_sSize}
        , m_pArray{m_sSize ? new int[m_sSize]() : nullptr}
    {
        // note that this is non-throwing, because of the data
        // types being used; more attention to detail with regards
        // to exceptions must be given in a more general case, however
        std::copy(other.m_pArray, other.m_pArray + m_sSize, m_pArray);
        std::cerr << "Called Copy constructor for object: " << this << std::endl;
    }

    // Destructor
    ~wrapper()
    {
        std::cerr << "Called Destructor for object: " << this << std::endl;
        delete [] m_pArray;
    }

private:
    size_t m_sSize;
    int*   m_pArray;
};

int main()
{
    wrapper first(7);
    wrapper second(first);
}
