// Rule # 9
// Never call virtual function in ctor or dtor

class Transaction
{
    public:
        Transaction();

        virtual void logTransaction() const = 0;
};

Transaction::Transaction()
{
    logTransaction();
}

class BuyTransaction : public Transaction
{
    public:
        virtual void logTransaction() const = 0;
};

class SellTransaction : public Transaction
{
    public:
        virtual void logTransaction() const = 0;
};

int main()
{
    BuyTransaction b;
}
