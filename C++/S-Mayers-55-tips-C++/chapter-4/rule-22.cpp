// Rule #22
// declare member data private.

class AccessLevels
{
    public:
        int getReadOnly () const       { return readOnly; }
        void setReadWrite (int value)  { readWrite = value; }
        int getreadWrite()             { return readWrite; }
        void setWriteOnly(int value)   { writeOnly = value; }
    private:
        int noAccess;
        int readOnly;
        int readWrite;
        int writeOnly;
};

int main()
{

}
