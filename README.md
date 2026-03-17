# Crypto Market Data Aggregator

A high-performance, multithreaded C++ application that aggregates real-time market data (Best Bid/Offer) from multiple exchanges (Binance, Coinbase) and identifies arbitrage opportunities.

## Dependencies

This project requires the following libraries:

*   **OpenSSL**: For secure WebSocket (WSS) connections.
*   **Boost**: Required by WebSocket++ for asynchronous I/O (Asio).
*   **nlohmann-json**: For parsing exchange JSON responses.
*   **WebSocket++ (websocketpp)**: Header-only library for C++ WebSocket client functionality.

### Installation (Arch Linux)
```bash
sudo pacman -S openssl boost nlohmann-json websocketpp
```

### Installation (Ubuntu/Debian)
```bash
sudo apt-get install libssl-dev libboost-all-dev nlohmann-json3-dev libwebsocketpp-dev
```

## Building

```bash
mkdir build && cd build
cmake ..
make
```
