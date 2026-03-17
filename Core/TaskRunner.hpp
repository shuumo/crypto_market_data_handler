#ifndef TASKRUNNER
#define TASKRUNNER

#include <memory>
#include <vector>

#include "../DataStore/DataStore.hpp"
#include "../ExchangeSocket/IExchangeSocket.hpp"

class Taskrunner {
public:
    static auto start(DataStore &map,
                      const std::vector<std::string> &symbols,
                      std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) -> int;
};

#endif
