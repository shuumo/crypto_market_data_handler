#include "DataPair.hpp" 

//std::mutex& DataPair::getMutex() {
//    return data_mutex;
//}

void DataPair::lock_atomic_flag() noexcept {
    while(true) {
        if (!lock.exchange(true, std::memory_order_acquire)) return;
        while(lock.load(std::memory_order_relaxed)) {
            __builtin_ia32_pause();
        }
    }
}

bool DataPair::try_atomic_flag() noexcept {
    return !lock.load(std::memory_order_relaxed) &&
           !lock.exchange(true, std::memory_order_acquire);
}

void DataPair::unlock_atomic_flag() noexcept {
    lock.store(false, std::memory_order_release);
}

DataPoint DataPair::getAsk() const {
    return ask;
}

DataPoint DataPair::getBid() const {
    return bid;
}

bool DataPair::setAsk(DataPoint ask) {
    this->ask = ask;
    return true;
}

bool DataPair::setBid(DataPoint bid) {
    this->bid = bid;
    return true;
}

