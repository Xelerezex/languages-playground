#include "tools.h"

class ThreadPool
{
    private:
        using UniqueFunction = std::packaged_task<void()>;
        struct
        {
            std::mutex mtx;
            std::queue<UniqueFunction> work_queue;
            bool aborting = false;
        } m_state;

        std::vector<std::thread> m_workers;
        std::condition_variable m_cv;
    public:
        ThreadPool(int size)
        {
            for (int i = 0; i < size; ++i)
            {
                m_workers.emplace_back([this] () { worker_loop(); });
            }
        }

        ~ThreadPool()
        {
            if (std::lock_guard lk(m_state.mtx); true)
            {
                m_state.aborting = true;
            }
            m_cv.notify_all();
            for (std::thread& t : m_workers)
            {
                t.join();
            }
        }

        void enqueue_task(UniqueFunction task)
        {
            if (std::lock_guard lk(m_state.mtx); true)
            {
                m_state.work_queue.push(std::move(task));
            }
            m_cv.notify_one();
        }
    private:
        void worker_loop()
        {
            while (true)
            {
                std::unique_lock lk(m_state.mtx);

                while (m_state.work_queue.empty() && !m_state.aborting)
                {
                    m_cv.wait(lk);
                }

                if (m_state.aborting)
                {
                    break;
                }

                assert(!m_state.work_queue.empty());
                UniqueFunction task = std::move(m_state.work_queue.front());
                m_state.work_queue.pop();

                lk.unlock();
                task();
            }
        }
    public:

        template<class F>
        auto async(F&& func)
        {
            using ResultType = std::invoke_result_t<std::decay_t<F>>;

            std::packaged_task<ResultType()> pt(std::forward<F>(func));
            std::future<ResultType> future = pt.get_future();

            UniqueFunction task
            (
                [pt = std::move(pt)] () mutable { pt(); }
            );

            enqueue_task(std::move(task));

            return future;
        }
};

int main()
{
    std::atomic<int> sum(0);
    ThreadPool tp(4);
    std::vector<std::future<int>> futures;
    for (int i = 0; i < 60'000; ++i)
    {
        auto f = tp.async([i, &sum] () {
            sum += i;
            return i;
        });
        futures.push_back(std::move(f));
    }
    assert(futures[42].get() == 42);
    assert(903 <= sum && sum <= 1799970000);
}
