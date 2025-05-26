#ifndef READER
#define READER 

#include "../DataStore/DataStore.hpp"
#include "../DataStore/NoAtomicDataPair.hpp"
#include "IFront.hpp"
#include <memory>

class ReaderManager {
public:
    void reader_main(DataStore &map, const std::vector<std::string> &symbols);
    DataStore create_snapshot(DataStore &map);
    bool output_best(std::unordered_map<std::string, NoAtomicDataPair> best_bid_asks, std::shared_ptr<IFront> output);
    std::unordered_map<std::string, NoAtomicDataPair> best_bid_ask_algorithm(DataStore &map);
};

#endif
