#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Core/TaskRunner.hpp"
#include "Loader/Loader.hpp"
#include "DataStore/DataStore.hpp"
#include "ExchangeSocket/IExchangeSocket.hpp"


void err(std::string description) {
    std::cout << "err in: " << description << '\n';
    exit(0);
}

int main() {
    // data structures 
    DataStore map;
    std::vector<std::string> symbols;
    std::vector<std::unique_ptr<IExchangeSocket>> exchanges;

    // load data for task runner 
    if(!Loader::get_symbols(symbols)) err("symbols");
    if(!Loader::get_exchanges(exchanges)) err("exchanges"); 
    if(!map.init_symbol_keys(symbols, exchanges.size())) err("key list init");

    // begin program
    return Taskrunner::start(map, symbols, exchanges);
}
