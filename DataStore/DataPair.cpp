#include "DataPair.hpp" 

auto DataPair::lock_atomic_flag() noexcept -> void {
    while(true) {
        if(!lock.exchange(true, std::memory_order_acquire)) return;
        while(lock.load(std::memory_order_relaxed)) CPU_PAUSE();
    }
}

auto DataPair::try_atomic_flag() noexcept -> bool {
    return !lock.load(std::memory_order_relaxed) &&
           !lock.exchange(true, std::memory_order_acquire);
}

auto DataPair::unlock_atomic_flag() noexcept -> void {
    lock.store(false, std::memory_order_release);
}

auto DataPair::getAsk() const -> DataPoint {
    return ask;
}

auto DataPair::getBid() const -> DataPoint {
    return bid;
}

auto DataPair::setAsk(const DataPoint& ask) -> bool {
    this->ask = ask;
    return true;
}

auto DataPair::setBid(const DataPoint& bid) -> bool {
    this->bid = bid;
    return true;
}

auto DataPair::valid_ask() const -> bool {
    return ask.price > 0;
}

auto DataPair::valid_bid() const -> bool {
    return bid.price > 0;
}
