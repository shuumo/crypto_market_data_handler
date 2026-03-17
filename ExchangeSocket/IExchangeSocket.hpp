#ifndef EXCHANGE
#define EXCHANGE

#include <string>
#include <vector>
#include <memory>

#include "../DataStore/DataStore.hpp"

class IExchangeSocket {
public:
    virtual ~IExchangeSocket() = default;
    virtual auto run_socket(DataStore &map,
                            const std::vector<std::string> &symbols,
                            std::vector<std::unique_ptr<IExchangeSocket>> &exchanges,
                            const int id) -> void = 0;
};

#endif
