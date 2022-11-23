#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>

bool more_data_to_prepare()
{
    return false;
}

class data_chunk
{
};

data_chunk prepare_data()
{
    return data_chunk{};
}

void process(data_chunk&)
{
}

bool is_last_chunk(data_chunk&)
{
    return true;
}

std::mutex mut;
std::queue<data_chunk> data_queue;
std::condition_variable data_cond;

void data_preparation_thread()
{
    while (more_data_to_prepare())
    {
        const data_chunk data = prepare_data();
        std::lock_guard<std::mutex> lock(mut);
        data_queue.push(data);
        data_cond.notify_one();
        std::cerr << "Called!" << std::endl;
    }
}

void data_processing_thread()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(
            lock,
            [] { return !data_queue.empty(); }
        );
        data_chunk data = data_queue.front();
        data_queue.pop();
        lock.unlock();
        process(data);
        if (is_last_chunk(data))
        {
            break;
        }
    }
}

int main()
{
    std::thread t1(data_preparation_thread);
    std::thread t2(data_processing_thread);

    t1.join();
    t2.join();
}
