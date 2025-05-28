#include "IExchangeSocket.hpp"
#include <iostream>
#include <random>

class TestSocket : public IExchangeSocket {
public:

    int intRand(const int & min, const int & max) {
        static thread_local std::mt19937 generator;
        std::uniform_int_distribution<int> distribution(min,max);
        return distribution(generator);
    }

    void run_socket(DataStore &map, const std::vector<std::string> &symbols, std::vector<std::unique_ptr<IExchangeSocket>> &exchanges, const int id) override {
        double bid{};
        double ask{};
        int i = 0;
        while(true) {
            for(const auto& symbol: symbols) {
                // get exchange data (latest best ask and bid)
                double bid_price = intRand(0, 100);
                double ask_price = intRand(0, 100);
                // create datapoints
                DataPoint ask;
                ask.price = ask_price;
                DataPoint bid;
                bid.price = bid_price;
                // access map
                map.write_bid(id, symbol, bid);
                //std::cout << "value " << bid_price << " checked bid for symbol: " << symbol << " by thread " << id << std::endl;
                map.write_ask(id, symbol, ask);
                //std::cout << "value " << ask_price << " checked ask for symbol: " << symbol << " by thread " << id << std::endl;
            }
        }
    }
};
