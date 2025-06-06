#ifndef AGUARD
#define AGUARD

#include "../DataStore/DataPair.hpp"

struct AtomicGuard {
    DataPair& lock;

    explicit AtomicGuard(DataPair& atomic_to_hold) noexcept : lock(atomic_to_hold) {
        lock.lock_atomic_flag();  
    }

    ~AtomicGuard() {
      lock.unlock_atomic_flag();
    }

    AtomicGuard(const AtomicGuard&) = delete;
    AtomicGuard& operator=(const AtomicGuard&) = delete;
};

#endif
