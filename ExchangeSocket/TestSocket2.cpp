#include "IExchangeSocket.hpp"
#include <iostream>

class TestSocket2 : public IExchangeSocket {
public:
    void run_socket(DataStore &map, std::vector<std::string> &symbols, std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) override {
        double bid = -1;
        double ask = -1;
        int i = 0;
        while(true) {
            for(const auto& symbol: symbols) {
                // get exchange data (latest best ask and bid) 
                map.write_bid(symbol, bid);
                std::cout << "written for symbol: " << symbol << std::endl;
                map.write_ask(symbol, ask);
                std::cout << "written for symbol: " << symbol << std::endl;
            }
            if(++i == 10) break;
        }
    }

    double get_map_bid(std::string &exchange, DataStore &map) override {
        return 0.0;
    }

    double get_map_ask(std::string &exchange, DataStore &map) override {
        return 0.0;
    }

    double get_exchange_bid() override {
        return 0.0;
    }

    double get_exchange_ask() override {
        return 0.0;
    }
};
