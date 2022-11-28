#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>

std::mutex external_mutex;
std::deque<std::packaged_task<void()>> tasks;

bool gui_shutdown_message_received() { return false; }
void get_and_process_gui_message()   {}

void gui_thread()
{
    while (!gui_shutdown_message_received())
    {
        get_and_process_gui_message();
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> lock(external_mutex);
            if (tasks.empty())
            {
                continue;
            }
            task = std::move(tasks.front());
            tasks.pop_front();
        }
        task();
    }
}

std::thread gui_bg_thread(gui_thread);

template <typename Func>
std::future<void> post_task_for_gui_thread(Func func)
{
    std::packaged_task<void()> task(func);
    std::future<void> result = task.get_future();
    std::lock_guard<std::mutex> lock(external_mutex);
    tasks.push_back(std::move(task));
    return result;
}

int main()
{

}
