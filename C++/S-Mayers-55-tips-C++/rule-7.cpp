// Rule #7
// Declare destructors virtual in a polymorphic base class

class TimeKeeper
{
    public:
        TimeKeeper();
        virtual ~TimeKeeper();              // !!!
};

class AtomicClock : public TimeKeeper
{};

class WaterClock : public TimeKeeper
{};

class WristClock : public TimeKeeper
{};

TimeKeeper * getTimeKeeper()
{
}

int main()
{
    TimeKeeper *ptk = getTimeKeeper();

    delete ptk; // With virtual it's ok
}
