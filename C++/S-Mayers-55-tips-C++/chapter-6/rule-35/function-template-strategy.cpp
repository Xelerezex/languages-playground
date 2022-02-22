

class GameCharacter;

int defaultHealthCalc (const GameCharacter& gc);

class GameCharacter
{
    public:
        typedef std::function<int (const GameCharacter&)> HealthCalcFunc;

        explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc)
        : healthFunc(hcf)
        {}

        int healthValue() const
        {
            return healthFunc(*this);
        }

    private:
        HealthCalcFunc healthFunc;
};

short calcHealth(const GameCharacter&);

struct healthCalculator
{
    int operator() (const GameCharacter&) const
    {}
};

class GameLevel
{
    public:
        float health(const GameCharacter&) const;
};

class EvilBadGay : public GameCharacter
{};

class EyeCandyCharacter : public GameCharacter
{};

int main()
{
    EvilBadGay ebg1(calcHealth);
    EyeCandyCharacter ecc1(healthCalculator*());
}
