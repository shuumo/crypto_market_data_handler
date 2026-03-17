#ifndef READER
#define READER 

#include "../DataStore/DataStore.hpp"
#include "../DataStore/NoAtomicDataPair.hpp"
#include "IFront.hpp"
#include <memory>

class ReaderManager {
public:
    auto reader_main(DataStore &map,
                     const std::vector<std::string> &symbols) -> void;

    auto output_best(std::unordered_map<std::string, NoAtomicDataPair> best_bid_asks,
                     std::shared_ptr<IFront> output) -> bool;

    auto best_bid_ask_algorithm(DataStore &map) -> std::unordered_map<std::string, NoAtomicDataPair>;
};

#endif
