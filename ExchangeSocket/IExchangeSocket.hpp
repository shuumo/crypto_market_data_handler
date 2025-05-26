#ifndef EXCHANGE
#define EXCHANGE

#include <string>
#include <vector>
#include <memory>

#include "../DataStore/DataStore.hpp"

class IExchangeSocket {
private:
    std::string exchange;
public:
    virtual ~IExchangeSocket() = default;
    virtual void run_socket(DataStore &map, const std::vector<std::string> &symbols,
                            std::vector<std::unique_ptr<IExchangeSocket>> &exchanges, const int id) = 0;
};

#endif
