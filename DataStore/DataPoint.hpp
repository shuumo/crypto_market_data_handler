#ifndef DATA_POINT
#define DATA_POINT

#include <string>

struct DataPoint {
    std::string exchange_name; // name of the exchange that set the DataPoint
    long long timestamp; // timestamp provided by exchange
    int chrono; // internal chrono timestamp
    double price{}; // ask or bid price
    long long call_id; // identifier for the DataPoint
};

#endif
