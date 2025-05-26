#ifndef FRONT
#define FRONT

#include <unordered_map>
#include "../DataStore/NoAtomicDataPair.hpp"

class IFront {
public:
    virtual ~IFront() = default;
    virtual void output_bid_ask(std::unordered_map<std::string, NoAtomicDataPair> &best_bid_asks) = 0;
};


#endif
