# Crypto Market Data Aggregator

A high-performance, modular C++ application designed for real-time market data ingestion and support for optional add on funtionality based on collected data via modularity, such as arbitrage detection. Its architecture is decoupled into specialized components: Exchange Sockets, Thread Safe DataStore and Reader Management, which together enable seamless integration of new exchanges and front end outputs while maintaining low latency.

## System Requirements

This project uses C++17 features and requires a compatible toolchain:

*   **C++ Compiler**: GCC 7+ or Clang 5+ (supporting C++17).
*   **CMake**: Version 3.10 or higher.
*   **Build System**: Make.

## Dependencies

This project requires the following libraries:

*   **OpenSSL**: For secure WebSocket (WSS) connections.
*   **nlohmann-json**: For parsing exchange JSON responses.
*   **WebSocket++ (websocketpp)**: Header-only library for C++ WebSocket client functionality.
*   **Boost**: Required by WebSocket++ for asynchronous I/O (Asio).


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
