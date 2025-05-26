#include <memory>
#include <thread>

#include "TaskRunner.hpp"
#include "../ExchangeSocket/TestSocket.cpp"
#include "../Front/ReaderManager.hpp"

int Taskrunner::start(DataStore &map, const std::vector<std::string> &symbols, 
                      std::vector<std::unique_ptr<IExchangeSocket>> &exchanges) {
    // launch writer threads
    std::vector<std::thread> writer_threads;
    int tid{};
    for(auto& ex: exchanges) {
        writer_threads.push_back(std::thread(
            &IExchangeSocket::run_socket,
            ex.get(),
            std::ref(map),
            std::ref(symbols),
            std::ref(exchanges),
            tid
        ));
        tid++;
    }

    // launch reader thread
    ReaderManager reader;
    std::thread reader_thread(
        &ReaderManager::reader_main,
        &reader,
        std::ref(map),
        std::ref(symbols)
    );

    // join threads
    for(std::thread& th: writer_threads) th.join();
    reader_thread.join();

    return 0;
}
