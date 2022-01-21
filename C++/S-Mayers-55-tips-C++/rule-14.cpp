// Rule 14
// Think twice at copy-classes, that rules recourses

class Mutex {};

void lock(Mutex *pm)
{}
void unlock(Mutex *pm)
{}


class Lock
{
    public:
        explicit Lock(Mutex *pm) : mutexPtr(pm)
        {
            lock(mutexPtr);
        }

        ~Lock()
        {
            unlock(mutexPtr);
        }
    private:
        Mutex *mutexPtr;
};

int main()
{
    Mutex m;

    {
        Lock ml(&m);
    }

    Lock ml1(&m);
    Lock ml2(ml1);
}
