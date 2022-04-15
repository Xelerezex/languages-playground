#include "tools.h"

#include <future>

using namespace std;

class Data
{
    public:
        Data(string data_) : data(data_)
        {
            cout << "Data constructed\n";
        }

        ~Data()
        {
            cout << "Data destructed\n";
        }

        const string& Get() const
        {
            return data;
        }

        string& Get()
        {
            return data;
        }

    private:
        string data;
};

void ShareResource(shared_ptr<Data> ptr)
{
    stringstream ss;
    ss << "Shared resource " << ptr->Get() << " in " << this_thread::get_id()
       << ", counter = " << ptr.use_count() << endl;
    cout << ss.str();
}

vector<future<void>> spawn()
{
    vector<future<void>> tasks;

    auto data = make_shared<Data>("meow");

    for (int i = 0; i < 10; ++i)
    {
        tasks.push_back(async(
            [=](){
                ShareResource(data);
            })
        );
    }

    return tasks;
}

int main()
{
    cout << "Spawning tasks...\n";
    auto tasks = spawn();
    cout << "Done spawning.\n";
}
