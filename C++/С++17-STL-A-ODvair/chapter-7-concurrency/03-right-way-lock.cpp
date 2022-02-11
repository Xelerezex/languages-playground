#include "tools.h"

template<typename M>
class my_unique_lock
{
    private:
        M* m_mtx = nullptr;
        bool m_locked = false;
    public:
        constexpr my_unique_lock() noexcept = default;
        constexpr my_unique_lock(M *p) noexcept :m_mtx(p) {}

        M *mutex() const noexcept { return m_mtx; }
        bool owns_lock() const noexcept { return m_locked; }

        void lock() { m_mtx -> lock(); m_locked = true; }
        void unlock() { m_mtx -> unlock(); m_locked = false; }

        my_unique_lock(my_unique_lock&& rhs) noexcept
        {
            m_mtx = std::exchange(rhs.m_mtx, nullptr);
            m_locked = std::exchange(rhs.m_locked, false);
        }

        my_unique_lock& operator=(my_unique_lock&& rhs)
        {
            if (m_locked)
            {
                unlock();
            }
            m_mtx = std::exchange(rhs.m_mtx, nullptr);
            m_locked = std::exchange(rhs.m_locked, false);
            return *this;
        }

        ~my_unique_lock()
        {
            if (m_locked)
            {
                unlock();
            }
        }
};

// lock_guard output
struct Lockbox
{
    std::mutex m_mtx;
    int m_value = 0;

    void locked_increment()
    {
        std::lock_guard<std::mutex> lk(m_mtx);
        m_value += 1;
    }

    void locked_decrement()
    {
        std::lock_guard lk(m_mtx);
        m_value -= 1;
    }
};

int main()
{

}
