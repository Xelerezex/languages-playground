#include <iostream>

class getc_iterator
{
    private:
        char ch;
    public:
        using iterator_category = std::input_iterator_tag;

        getc_iterator()
            : ch(getc(stdin))
        {}

        char operator*() const
        {
            return ch;
        }

        auto& operator++()
        {
            ch = getc(stdin);
            return *this;
        }

        auto operator++(int)
        {
            auto result {*this};
            ++*this;
            return result;
        }

        bool operator==(const getc_iterator&) const
        {
            return false;
        }

        bool operator!=(const getc_iterator&) const
        {
            return true;
        }
};

class putc_iterator
{
    private:
        struct proxy
        {
            void operator=(char ch)
            {
                putc(ch, stdout);
            }
        };
    public:
        using iterator_category = std::output_iterator_tag;

        proxy operator*() const
        {
            return proxy{};
        }

        auto& operator++()
        {
            return *this;
        }

        auto& operator++(int)
        {
            return *this;
        }

        bool operator==(const putc_iterator&) const
        {
            return false;
        }

        bool operator!=(const putc_iterator&) const
        {
            return true;
        }
};

int main()
{
    putc_iterator it;

    for (char ch : {'h', 'e', 'l', 'l', 'o', '\n'})
    {
        *it++ = ch;
    }
}
