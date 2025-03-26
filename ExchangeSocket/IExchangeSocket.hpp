#ifndef EXCHANGE
#define EXCHANGE

#include <string>
#include <vector>

class IExchangeSocket {
private:
    std::string exchange;
    std::vector<std::string> symbols;
public:
    virtual void run_socket() = 0;
    virtual void get_bid() const = 0;
    virtual void get_ask() const = 0;
};

#endif
