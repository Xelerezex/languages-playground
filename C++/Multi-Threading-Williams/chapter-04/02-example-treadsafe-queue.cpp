#include <memory>

template <typename T>
class threadsafe_queue
{
public:
        treadsafe_queue();
        treadsafe_queue(const treadsafe_queue&);
        treadsafe_queue& operator=(const treadsafe_queue&) = delete;

        void push(T new_value);

        bool try_pop(T& value);
        std::shared_ptr<T> try_pop();

        void wait_and_pop(T& value);
        std::shared_ptr<T> wait_and_pop();

        bool empty() const;
};

int main()
{

}
