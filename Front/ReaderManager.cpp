#include "ReaderManager.hpp"
#include "CliFront.cpp"
#include "../DataStore/NoAtomicDataPair.hpp"
#include <memory>

void ReaderManager::reader_main(DataStore &map, const std::vector<std::string> &symbols) {
    //create output pointers
    std::shared_ptr<IFront> cli_output(std::make_shared<CliFront>());
 
    // main reader loop
    int i{};
    while(true) {
        auto best_bid_asks = best_bid_ask_algorithm(map);
        output_best(best_bid_asks, cli_output);
        //if(++i == 10000) exit(1);
    }
}

bool ReaderManager::output_best(std::unordered_map<std::string, NoAtomicDataPair> best_bid_asks, std::shared_ptr<IFront> output) {
    output->output_bid_ask(best_bid_asks);
    return {};
}

std::unordered_map<std::string, NoAtomicDataPair> ReaderManager::best_bid_ask_algorithm(DataStore &map) {
    std::unordered_map<std::string, NoAtomicDataPair> best_map;
    for(auto& symbol: map) {
        DataPoint best_ask;
        best_ask.price = std::numeric_limits<double>::max();
        DataPoint best_bid;
        best_bid.price = std::numeric_limits<double>::min();
        std::string this_symbol = symbol.first;

        int id = 0;
        for(auto& exchange: symbol.second) {
            DataPoint ask = map.get_ask(id, this_symbol);
            if(best_ask.price > ask.price) best_ask = ask;
            DataPoint bid = map.get_bid(id, this_symbol);
            if(best_bid.price < bid.price) best_bid = bid;
            id++;
        }

        best_map[this_symbol].ask = best_ask;
        best_map[this_symbol].bid = best_bid;
    }
    return best_map;
}


