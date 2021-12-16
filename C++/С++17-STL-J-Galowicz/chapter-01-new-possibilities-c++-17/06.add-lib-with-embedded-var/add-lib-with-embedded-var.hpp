#pragma once
#include <string>

class process_monitor {
    public:
        static const inline std::string standart_string
                {"some static globally available string"};
};

/*WITH INLINE WARIABLE NO ODR ERROR*/
inline process_monitor global_process_monitor;
