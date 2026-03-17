#include "IExchangeSocket.hpp"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

class TestSocket : public IExchangeSocket {
public:

    auto intRand(const int & min, const int & max) -> int {
        static thread_local std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(min,max);
        return distribution(generator);
    }

    auto run_socket(DataStore &map,
                    const std::vector<std::string> &symbols, 
                    std::vector<std::unique_ptr<IExchangeSocket>> &exchanges,
                    const int id) -> void override {
        while(true) {
            for(const auto& symbol: symbols) {
                auto bid_price = static_cast<double>(intRand(50, 100));
                auto ask_price = bid_price + static_cast<double>(intRand(1, 5)) * 0.1;

                auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count();

                auto bid = DataPoint{};
                bid.price = bid_price;
                bid.exchange_name = "TestEx";
                bid.timestamp = now;

                auto ask = DataPoint{};
                ask.price = ask_price;
                ask.exchange_name = "TestEx";
                ask.timestamp = now;

                map.write_bid(id, symbol, bid);
                map.write_ask(id, symbol, ask);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};
