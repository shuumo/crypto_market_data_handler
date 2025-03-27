#include <iostream>

#include "TaskRunner.hpp"

int Taskrunner::start(DataStore &map, std::vector<std::string> &symbols, std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) {
    std::cout << "Task runner was started, recieved map, symbols and exchanges" << '\n'; 
    for(const auto& i: symbols) {
        std::cout << i << '\n';
    }
    return 0;
}
