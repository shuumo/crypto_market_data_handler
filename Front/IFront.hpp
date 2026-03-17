#ifndef FRONT
#define FRONT

#include <unordered_map>
#include "../DataStore/NoAtomicDataPair.hpp"

class IFront {
public:
    virtual ~IFront() = default;
    virtual auto output_bid_ask(std::unordered_map<std::string, NoAtomicDataPair> &best_bid_asks) -> void = 0;
};

#endif
