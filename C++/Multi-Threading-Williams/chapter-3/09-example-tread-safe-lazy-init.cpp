#include <mutex>

class connection_info
{};

class data_packet
{};

class connection_handle
{
public:
    void send_data (data_packet const&)
    {}
    data_packet receive_data()
    {
        return data_packet();
    }
};

class remote_connection_manager
{
public:
    connection_handle open(connection_info const&)
    {
        return connection_handle{};
    }
} connection_manager;

class X
{
public:
    X(const connection_info &connection_details_)
        : connection_details{connection_details_}
    {}

    void send_data(const data_packet &data)
    {
        std::call_once(connection_init_flag, &X::open_connection, this);
        connection.send_data(data);
    }

    data_packet receive_data()
    {
        std::call_once(connection_init_flag, &X::open_connection, this);
        return connection.receive_data();
    }

private:
    void open_connection()
    {
        connection = connection_manager.open(connection_details);
    }

private:
    connection_info   connection_details;
    connection_handle connection;
    std::once_flag    connection_init_flag;
};

int main()
{

}
