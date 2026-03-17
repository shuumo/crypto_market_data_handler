#include "Loader.hpp"
#include "../ExchangeSocket/BinanceSocket.cpp"
#include "../ExchangeSocket/CoinbaseSocket.cpp"
#include "../ExchangeSocket/TestSocket.cpp"

auto Loader::get_symbols(std::vector<std::string> &symbols) -> bool {
    symbols.clear();
    symbols.push_back("btcusdt");
    symbols.push_back("ethusdt");
    symbols.push_back("solusdt");
    return true;
}

auto Loader::get_exchanges(std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) -> bool {
    exchanges.clear();
    exchanges.push_back(std::make_unique<BinanceSocket>());
    exchanges.push_back(std::make_unique<CoinbaseSocket>());
    return true;
}
