class GameCharacter;

int defaultHealthCalc (const GameCharacter& gc);

class GameCharacter
{
    public:
        typedef int (*HealthCalcFunc) (const GameCharacter&);

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

class EvilBadGay : public GameCharacter
{
    public:
        explicit EvilBadGay(HealthCalcFunc hcf = defaultHealthCalc)
        : GameCharacter(hcf)
        {}
};


int loseHealthQuickly(const GameCharacter&)
{}

int loseHealthSlowly(const GameCharacter&)
{}

int main()
{
    EvilBadGay ebg1(loseHealthQuickly);
    EvilBadGay ebg2(loseHealthSlowly);
}
