#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Core/TaskRunner.hpp"
#include "Loader/Loader.hpp"
#include "DataStore/DataStore.hpp"
#include "ExchangeSocket/IExchangeSocket.hpp"


void failure() {
    std::cout << "failure" << '\n';
    exit(0);
}

int main() {
    // pre-loader data setup
    DataStore map;
    std::vector<std::string> symbols; 
    std::vector<std::unique_ptr<IExchangeSocket>> exchanges;

    // load data to program
    if(!Loader::get_symbols(symbols)) failure();
    if(!Loader::get_exchanges(exchanges)) failure(); 
    //map.init_keys(symbols);

    // begin program
    Taskrunner::start(map, symbols, exchanges);

    return 0;
}
