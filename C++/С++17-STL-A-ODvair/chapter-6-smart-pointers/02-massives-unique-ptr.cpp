#include "tools.h"

struct fcloser
{
    void operator()(FILE *fp) const
    {
        fclose(fp);
    }

    static auto open(const char *name, const char *mode)
    {
        return std::unique_ptr<FILE, fcloser>(fopen(name, mode));
    }
};

void use(FILE *)
{}

int main()
{
    {
        auto f = fcloser::open("test.txt", "r");
        use(f.get());
    }
}
