#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Core/TaskRunner.hpp"
#include "Loader/Loader.hpp"
#include "DataStore/DataStore.hpp"
#include "ExchangeSocket/IExchangeSocket.hpp"


auto err(std::string description) -> void {
    std::cout << "err in: " << description << '\n';
    exit(0);
}

auto main() -> int {
    // data structures 
    auto map = DataStore{};
    auto symbols = std::vector<std::string>{};
    auto exchanges = std::vector<std::unique_ptr<IExchangeSocket>>{};

    // load data for task runner 
    if(!Loader::get_symbols(symbols)) err("symbols");
    if(!Loader::get_exchanges(exchanges)) err("exchanges"); 
    if(!map.init_symbol_keys(symbols, exchanges.size())) err("key list init");

    // begin program
    return Taskrunner::start(map, symbols, exchanges);
}
