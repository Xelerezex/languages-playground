#include <memory>

template <typename T>
class threadsafe_queue
{
public:
        treadsafe_queue();
        treadsafe_queue(const treadsafe_queue&);
        treadsafe_queue& operator=(const treadsafe_queue&) = delete;

        /**********************************************************************/
        void push(T new_value)
        {
                std::lock_guard<std::mutex> lock(mut);
                data_queue.push(new_value);
                data_cond.notify_one();
        }
        /**********************************************************************/

        /**********************************************************************/
        bool try_pop(T& value);
        std::shared_ptr<T> try_pop();
        /**********************************************************************/

        /**********************************************************************/
        void wait_and_pop(T& value)
        {
                std::unique_lock<std::mutex> lock(mut);
                data_cond.wait(lock, [this] { return !data_queue.empty(); });
                value = data_queue.front();
                data_queue.pop();
        }

        std::shared_ptr<T> wait_and_pop();
        /**********************************************************************/

        /**********************************************************************/
        bool empty() const;
        /**********************************************************************/

private:
        std::mutex mut;
        std::queue<T> data_queue;
        std::condition_variable data_cond;
};

class data_chunk
{
};

data_chunk prepare_data()
{
    return data_chunk{};
}

bool more_data_to_prepare()
{
    return false;
}

void process(data_chunk&)
{
}

bool is_last_chunk(data_chunk&)
{
    return true;
}

threadsafe_queue<data_chunk> data_queue;

void data_preparation_thread()
{
    while(more_data_to_prepare())
    {
        data_chunk const data=prepare_data();
        data_queue.push(data);
    }
}

void data_processing_thread()
{
    while(true)
    {
        data_chunk data;
        data_queue.wait_and_pop(data);
        process(data);
        if(is_last_chunk(data))
            break;
    }
}

int main()
{

    std::thread t1(data_preparation_thread);
    std::thread t2(data_processing_thread);

    t1.join();
    t2.join();
}
