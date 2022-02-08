#include "tools.h"

struct DangerousWatcher
{
    int *m_ptr = nullptr;

    void watch(const std::shared_ptr<int>& p)
    {
        m_ptr = p.get();
    }

    int current_value() const
    {
        return *m_ptr;
    }
};

struct NotReallyAWatcher
{
    std::shared_ptr<int> m_ptr;

    void watch(const std::shared_ptr<int>& p)
    {
        m_ptr = p;
    }

    int current_value() const
    {
        return *m_ptr;
    }
};

struct CorrectWatcher
{
    std::weak_ptr<int> m_ptr;

    void watch(const std::shared_ptr<int>& p)
    {
        m_ptr = std::weak_ptr<int>(p);
    }

    int current_value() const
    {
        if (auto p = m_ptr.lock())
        {
            return *p;
        }
        else
        {
            throw "It has no value; it's been deallocated!";
        }
    }
};

int main()
{

}
