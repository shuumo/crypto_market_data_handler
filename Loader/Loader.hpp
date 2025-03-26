#include <vector>
#include <string>
#include <memory>

#include "../ExchangeSocket/IExchangeSocket.hpp"

class Loader {
private:
    
public:
    static bool get_symbols(std::vector<std::string> &symbols);
    static bool get_exchanges(std::vector<std::unique_ptr<IExchangeSocket>> &exchanges);
};
