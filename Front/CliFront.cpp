#include <iostream>
#include <iomanip>
#include "IFront.hpp"

class CliFront : public IFront {
public:
    auto output_bid_ask(std::unordered_map<std::string, NoAtomicDataPair> &best_bid_asks) -> void override {
        auto found = bool{false};
        for(const auto& pair : best_bid_asks) {
            const auto& ask = pair.second.ask;
            const auto& bid = pair.second.bid;

            if(bid.price <= 0 || ask.price <= 0) continue;

            found = true;
            auto spread = double{ask.price - bid.price};

            std::cout << "[SYMBOL: " << std::setw(8) << pair.first << "] "
                      << "Bid: " << std::fixed << std::setprecision(2) << std::setw(10) << bid.price 
                      << " (" << bid.exchange_name << ") | "
                      << "Ask: " << std::fixed << std::setprecision(2) << std::setw(10) << ask.price 
                      << " (" << ask.exchange_name << ") | "
                      << "Spread: " << std::setw(8) << spread;

            if(spread < 0) std::cout << "  *** ARBITRAGE! ***";
            std::cout << std::endl;
        }
        if(found) std::cout << "--------------------------------------------------------------------------------" << std::endl;
    };
};
