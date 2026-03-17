# Crypto Market Data Aggregator

A high-performance, modular C++ application designed for real-time market data ingestion and arbitrage detection. Its architecture is decoupled into specialized components: Exchange Sockets, Thread Safe DataStore and Reader Management, which together enable seamless integration of new exchanges and front end outputs while maintaining low latency.

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

## Building

```bash
mkdir build && cd build
cmake ..
make
```
