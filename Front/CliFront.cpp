#include <iostream>

#include "IFront.hpp"

class CliFront : public IFront {
    void output_bid_ask(std::unordered_map<std::string, NoAtomicDataPair> &best_bid_asks) override {
        for(const auto& pair: best_bid_asks) {
            double spread = pair.second.ask.price - pair.second.bid.price;
            if(pair.second.bid.price == 0 || pair.second.ask.price == 0) return;
            if(spread < 0) {
                std::cout << "Arbitrage Opportunity Found!" << '\n';
                std::cout << "Symbol " << pair.first << " had best ask of " << pair.second.ask.price
                    << " and a best bid of " << pair.second.bid.price << '\n';
                std::cout << "The spread is " << spread << '\n';
                std::cout << '\n';
            }
        }
    };
};
