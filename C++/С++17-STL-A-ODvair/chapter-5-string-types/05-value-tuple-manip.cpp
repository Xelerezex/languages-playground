#include "tools.h"

template<class T>
constexpr size_t tuple_size(T&&)
{
    return std::tuple_size_v<std::remove_reference_t<T>>;
}

template<class... Ts>
constexpr size_t simpler_tuple_size(const std::tuple<Ts...>&)
{
    return sizeof...(Ts);
}

int main()
{

}
