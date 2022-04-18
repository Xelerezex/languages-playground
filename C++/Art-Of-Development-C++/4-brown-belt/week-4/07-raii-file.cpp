#include "tools.h"

#include <cstdio>

class File
{
    private:
       FILE* f;

    public:
        File(const std::string& filename)
        {
            f = fopen(filename.c_str(), "w");

            if (f == nullptr)
            {
                throw std::runtime_error("Cannot open " + filename);
            }
        }

        void Write(const std::string& line)
        {
            fputs("Hello world\n", f);
            fputs("This file is written with raii fputs\n", f);
            fputs(line.c_str(), f);
        }

        ~File()
        {
            fclose(f);
        }
};

int main()
{
    try
    {
        File f("output.txt");
        f.Write("Smth str\n");
    }
    catch (...)
    {
        std::cout << "Cannot open file\n";
    }
}
