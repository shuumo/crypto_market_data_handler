#include <iostream>

#include "IFront.hpp"

class CliFront : public IFront {
    void output_bid_ask(std::unordered_map<std::string, NoAtomicDataPair> &best_bid_asks) override {
        for(const auto& pair: best_bid_asks) {
            std::cout << "Symbol " << pair.first << " had best ask of " << pair.second.ask.price
                << " and a best bid of " << pair.second.bid.price << '\n';
        }
    };
};
