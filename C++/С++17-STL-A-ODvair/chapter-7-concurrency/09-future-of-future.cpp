#include "tools.h"

class Data {};
class Connection {};

Connection slowly_open_connection()
{
    Connection slow;
    return slow;
}

Data slowly_get_data_from_disk()
{
    Data slow;
    return slow;
}

Data slowly_get_data_from_connection(Connection &conn)
{
    Data slow;
    return slow;
}

template<class T>
auto pf()
{
    std::promise<T> p;
    std::future<T>  f = p.get_future();

    return std::make_pair(std::move(p), std::move(f));
}

int main()
{
    {
        auto [p1, f1] = pf<Connection>();
        auto [p2, f2] = pf<Data>();
        auto [p3, f3] = pf<Data>();

        auto t1 = std::thread (
            [p1 = std::move(p1)] () mutable
            {
                Connection conn = slowly_open_connection();
                p1.set_value(conn);
            }
        );

        auto t2 = std::thread (
            [p2 = std::move(p2)] () mutable
            {
                Data data = slowly_get_data_from_disk();
                p2.set_value(data);
            }
        );

        auto t3 = std::thread (
            [p3 = std::move(p3)] () mutable
            {
                Data data = slowly_get_data_from_connection(f1.get());
                p3.set_value(data);
            }
        );

        bool success = (f2.get() == f3.get());
        assert(success);
    }
    {
        auto f1 = std::async(slowly_open_connection);
        auto f2 = std::async(slowly_get_data_from_disk);
        auto f3 = std::async(
            [f1 = std::move(f1)] () mutable
            {
                return slowly_get_data_from_connection(f1.get());
            }
        );

        bool success = (f2.get() == f3.get());
        assert(success);
    }

}
