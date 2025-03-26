#include "IExchangeSocket.hpp"

class BinanceSocket : IExchangeSocket {
private:
    void create_connection() {
    
    }

public: 
    virtual void run_socket() override {
        // open a tcp/ip connection 
        
        while(true) {
            // loop over desired symbols
            // get ask and bid
            // compare with hashmap 
            // set or continue
        }
    }

    virtual void get_bid() const override {

    }

    virtual void get_ask() const override {

    }
};
