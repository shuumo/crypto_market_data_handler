#include "ReaderManager.hpp"
#include "IFront.hpp"
#include "../DataStore/NoAtomicDataPair.hpp"
#include <memory>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <iostream>

auto ReaderManager::reader_main(DataStore &map,
                                const std::vector<std::string> &symbols) -> void { }

auto ReaderManager::output_best(std::unordered_map<std::string, NoAtomicDataPair> best_bid_asks,
                                std::shared_ptr<IFront> output) -> bool {
    if(output) {
        output->output_bid_ask(best_bid_asks);
        return true;
    }
    return false;
}

auto ReaderManager::best_bid_ask_algorithm(DataStore &map) -> std::unordered_map<std::string, NoAtomicDataPair> {
    auto best_map = std::unordered_map<std::string, NoAtomicDataPair>{};

    auto lock = std::shared_lock{map.get_mutex()};

    for(auto it = map.begin(); it != map.end(); ++it) {
        auto best_ask = DataPoint{};
        best_ask.price = std::numeric_limits<double>::max();
        auto best_bid = DataPoint{};
        best_bid.price = std::numeric_limits<double>::min();

        const auto& this_symbol = it->first;
        const auto& exchange_vec = it->second;

        for(auto id = size_t{0}; id < exchange_vec.size(); ++id) {
            auto ask = map.get_ask(static_cast<int>(id), this_symbol);
            if(ask.price > 0 && ask.price < best_ask.price) best_ask = ask;

            auto bid = map.get_bid(static_cast<int>(id), this_symbol);
            if(bid.price > 0 && bid.price > best_bid.price) best_bid = bid;
        }

        if(best_ask.price != std::numeric_limits<double>::max()) best_map[this_symbol].ask = best_ask;
        if(best_bid.price != std::numeric_limits<double>::min()) best_map[this_symbol].bid = best_bid;
    }
    return best_map;
}
