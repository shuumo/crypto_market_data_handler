#include <memory>
#include <thread>
#include <vector>

#include "TaskRunner.hpp"
#include "../Front/ReaderManager.hpp"
#include "../Front/CliFront.cpp"

auto Taskrunner::start(DataStore &map,
                       const std::vector<std::string> &symbols, 
                       std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) -> int {

    auto writer_threads = std::vector<std::thread>{};
    for(auto id = size_t{0}; id < exchanges.size(); ++id) {
        writer_threads.push_back(std::thread(
            &IExchangeSocket::run_socket,
            exchanges[id].get(),
            std::ref(map),
            std::ref(symbols),
            std::ref(exchanges),
            static_cast<int>(id)
        ));
    }

    auto reader_thread = std::thread([&map, &symbols]() {
        auto manager = ReaderManager{};
        auto cli_output = std::make_shared<CliFront>();

        while(true) {
            auto best_bid_asks = manager.best_bid_ask_algorithm(map);
            manager.output_best(best_bid_asks, cli_output);
            std::this_thread::yield();
        }
    });

    for(auto& th : writer_threads) if(th.joinable()) th.join();
    if(reader_thread.joinable()) reader_thread.join();

    return 0;
}
