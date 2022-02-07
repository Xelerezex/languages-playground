// Rule #26
// Delay defining variables as much as possible

#include "tools.h"

const int MinimumPasswordLength = 8;

void encrypt(std::string password)
{
}

std::string encryptPassword(const std::string& password)
{
    using namespace std;

    // string encrypted;    FROM HERE

    if (password.length() < MinimumPasswordLength)
    {
        throw logic_error("Too short password");
    }

    // MOVE HERE

    string encrypted(password);

    encrypt(password);

    return encrypted;
}

int main()
{
    encryptPassword("012345678");
}
