#include <vector>
#include <string>
#include <memory>

#include "../ExchangeSocket/IExchangeSocket.hpp"

class Loader {
public:
    static auto get_symbols(std::vector<std::string> &symbols) -> bool;
    static auto get_exchanges(std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) -> bool;
};
