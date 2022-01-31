// Rule #16
// Use the same form of new & delete

int main()
{
    std::string *stringPtr1 = new std::string;
    std::string *stringPtr2 = new std::string[100];

    delete   stringPtr1;
    delete[] stringPtr2;
}
