#include "Loader.hpp"

bool Loader::get_symbols(std::vector<std::string> &symbols) {
    symbols.push_back("BTCUSDT");
    return true;
}



bool Loader::get_exchanges(std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) {
    
    return true;
}



