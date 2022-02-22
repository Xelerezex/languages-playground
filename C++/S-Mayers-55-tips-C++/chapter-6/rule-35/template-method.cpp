class GameCharacter
{
    public:
        int healthValue() const
        {
            int retVal = doHealthValue();

            return retValue;
        }

    private:
        virtual int doHealthValue() const
        {}
};
