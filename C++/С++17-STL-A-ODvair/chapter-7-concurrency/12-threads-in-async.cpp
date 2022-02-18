#include "tools.h"

template<class F>
auto my_async(F&& func)
{
    using ResultType = std::invoke_result_t<std::decay_t<F>>;
    using PromiseType = std::promise<ResultType>;
    using FutureType = std::future<ResultType>;

    PromiseType promise;
    FutureType future = promise.get_future();

    auto t = std::thread(
        [func = std::forward<F>(func), promise = std::move(promise)] () mutable {
            try
            {
                ResultType result = func();
                promise.set_value(result);
            }
            catch(...)
            {
                promise.set_exception(std::current_exception());
            }
        }
    );

    return future;
}

int main()
{
    int i = 0;

    auto future = my_async(
        [&] () {
            i += 1;
        }
    );
}
