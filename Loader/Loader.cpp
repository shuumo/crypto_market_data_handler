#include "Loader.hpp"

// IExchangeScokets
#include "../ExchangeSocket/TestSocket.cpp"


bool Loader::get_symbols(std::vector<std::string> &symbols) {
    symbols.push_back("BTCUSDT");
    return true;
}

bool Loader::get_exchanges(std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) {
    exchanges.push_back(std::make_unique<TestSocket>());
    return true;
}



