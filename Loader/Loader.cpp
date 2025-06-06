#include "Loader.hpp"

// IExchangeScokets
#include "../ExchangeSocket/TestSocket.cpp"
#include "../ExchangeSocket/BinanceSocket.cpp"
#include "../ExchangeSocket/KucoinSocket.cpp"


bool Loader::get_symbols(std::vector<std::string> &symbols) {
    symbols.push_back("btcusdt");
    symbols.push_back("ltcusdt");
    symbols.push_back("ethusdt");
    return true;
}

bool Loader::get_exchanges(std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) {
    //exchanges.push_back(std::make_unique<TestSocket>());
    //exchanges.push_back(std::make_unique<BinanceSocket>());
    exchanges.push_back(std::make_unique<KucoinSocket>());
    return true;
}



