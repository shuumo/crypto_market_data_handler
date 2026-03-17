#ifndef DATA_POINT
#define DATA_POINT

#include <string>

struct DataPoint {
    std::string exchange_name;
    long long timestamp;
    int chrono;
    double price{};
    long long call_id;
};

#endif
