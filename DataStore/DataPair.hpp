#ifndef DATA_PAIR
#define DATA_PAIR

#include "../DataStore/DataPoint.hpp"
#include <atomic>

#if defined(__i386__) || defined(__x86_64__)
    #include <immintrin.h>
    #define CPU_PAUSE() _mm_pause()
#elif defined(__arm__) || defined(__aarch64__)
    #define CPU_PAUSE() __asm__ __volatile__("yield" ::: "memory")
#else
    #define CPU_PAUSE() std::this_thread::yield()
#endif

class DataPair {
private:
    std::atomic<bool> lock = {false};
    DataPoint bid;
    DataPoint ask;

public:
    auto valid_ask() const -> bool;
    auto valid_bid() const -> bool;

    auto getBid() const -> DataPoint;
    auto getAsk() const -> DataPoint;

    auto lock_atomic_flag() noexcept -> void;
    auto try_atomic_flag() noexcept -> bool;
    auto unlock_atomic_flag() noexcept -> void;

    auto setBid(const DataPoint& bid) -> bool;
    auto setAsk(const DataPoint& ask) -> bool;
};

#endif
