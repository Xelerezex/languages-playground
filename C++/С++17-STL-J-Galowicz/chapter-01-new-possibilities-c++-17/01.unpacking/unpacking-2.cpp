#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <tuple>


std::tuple<std::string, std::chrono::system_clock::time_point, unsigned> stock_info(const std::string &name) {
    const std::chrono::time_point<std::chrono::system_clock> now =
        std::chrono::system_clock::now();

    return std::make_tuple(name, now, 1600);
}


int main() {


    // SECOND WAY - GET THREE VALUES OUT OF TUPLES:
    auto [name, valid_time, price] = stock_info("INTC");


    const std::time_t t_c = std::chrono::system_clock::to_time_t(valid_time);


    std::cout << "INFO: name: "
              << name << " time: "
              << std::put_time(std::localtime(&t_c), "%F %T.") << " price: "        // put_time - member of iomanip
              << price << '\n';


    return 0;
}
