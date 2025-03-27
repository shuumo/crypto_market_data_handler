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
    // data structures 
    DataStore map;
    std::vector<std::string> symbols; 
    std::vector<std::unique_ptr<IExchangeSocket>> exchanges;

    // load data for task runner 
    if(!Loader::get_symbols(symbols)) failure();
    if(!Loader::get_exchanges(exchanges)) failure(); 
    if(!map.init_keys(symbols)) failure();

    // begin program
    return Taskrunner::start(map, symbols, exchanges);
}
