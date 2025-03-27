#ifndef EXCHANGE
#define EXCHANGE

#include <string>
#include <vector>
#include <memory>

#include "../DataStore/DataStore.hpp"

class IExchangeSocket {
private:
    std::string exchange;
    std::vector<std::string> symbols;
public:
    virtual ~IExchangeSocket() = default; 
    virtual void run_socket(DataStore &map, std::vector<std::string> &symbols, std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) = 0;
    virtual void get_map_bid(std::string &exchange, DataStore &map) = 0;
    virtual void get_map_ask(std::string &exchange, DataStore &map) = 0;
};

#endif
