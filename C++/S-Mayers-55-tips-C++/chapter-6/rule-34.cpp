// Rule #34
// Distinguish between interface inheritance and implementation inheritance

#include "tools.h"

class Airport {};

class Airplane
{
    public:
        virtual void fly(const Airport& destination) = 0;

};

void Airplane::fly(const Airport& destination)
{
}

class ModelA : public Airplane
{
    public:
        virtual void fly(const Airport& destination)
        {
            Airplane::fly(destination);
        }
};

class ModelB : public Airplane
{
    public:
        virtual void fly(const Airport& destination)
        {
            Airplane::fly(destination);
        }
};

class ModelC : public Airplane
{
    public:
        virtual void fly(const Airport& destination);
};

void ModelC::fly(const Airport& destination)
{

}

int main()
{

}
