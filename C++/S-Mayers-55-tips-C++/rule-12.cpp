// Rule #12
// Copy all parts of object
#include <iostream>

void logCall(const std::string& funcName)
{
    std::cerr << funcName << std::endl;
}
class Date {};

class Customer
{
    public:
        Customer(const Customer& rhs);
        Customer& operator=(const Customer& rhs);
    private:
        std::string name;
        Date lastTransaction;
};

Customer::Customer(const Customer& rhs) : name(rhs.name)
{
    logCall("Copy ctor Customer");
}

Customer& Customer::operator=(const Customer& rhs)        // Doesn't copy all fields!!!
{
    logCall("Copy operator= Customer");
    name = rhs.name;
    return *this;
}

class PriorityCustomer : public Customer
{
    public:
        PriorityCustomer(const PriorityCustomer& rhs);
        PriorityCustomer& operator=(const PriorityCustomer& rhs);
    private:
        int priority;
};


PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs) : Customer(rhs), priority(rhs.priority)
{
    logCall("Copy ctor PriorityCustomer");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
    logCall("Copy operator= PriorityCustomer");
    Customer::operator=(rhs);
    priority = rhs.priority;
    return *this;
}


int main()
{

}
