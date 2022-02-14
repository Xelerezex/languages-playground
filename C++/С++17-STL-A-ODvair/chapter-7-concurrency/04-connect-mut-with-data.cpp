#include "tools.h"

template<class Data>
class Guarded
{
    // private:
        std::mutex m_mtx;
        Data m_data;

        class Handle
        {
            private:
                std::unique_lock<std::mutex> m_lk;
                Data *m_ptr;
            public:
                Handle(std::unique_lock<std::mutex> lk, Data *p) : m_lk(std::move(lk)), m_ptr(p) {}
                auto operator->() const { return m_ptr; }
        };
    public:
        Handle lock()
        {
            std::unique_lock lk{m_mtx};
            return Handle{std::move(lk), &m_data};
        }
};

class StreamingAverage
{
    private:
        struct Guts
        {
            double m_sum = 0;
            int m_count  = 0;
        };
        Guarded<Guts> m_sc;
        double m_last_average = 0;
    public:
        void add_value(double x)
        {
            m_sc.lock() -> m_sum   += x;
            m_sc.lock() -> m_count += 1;
        }

        double get_sum()
        {
            return m_sc.lock() -> m_sum;
        }

        double get_count()
        {
            return m_sc.lock() -> m_count;
        }

        double get_current_average()
        {
            auto h = m_sc.lock();
            return get_sum() / get_count();
        }

        double get_last_average() const
        {
            return m_last_average;
        }

        double get_current_count()
        {
            return m_sc.lock() -> m_count;
        }
};

int main()
{

}
