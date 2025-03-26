This program is a Crypto Market Data Aggregator, aiming to utilize efficient concurrent programming, websockets and rest api. It will be implemented in C++23, and cmake/makefile for building.

## MVP REQUIREMENTS IN FUNCTIONALITY
1. Fetch real-time data from three cryptocurrency exchanges. (with precise timestamps)
2. Normalize the data
3. Aggregated data outputed to CLI quickly, in real time. also write to csv.
4. auto-trade found arbitrage opportunities (and lose all your money)

## ARCHITECTURE (subject to change as i go)
#### Interfaces
- `ExchangeSocket` for normalizing data output from different exchanges. Each implementation of this interface is for each exchange. 
- `Front` for outputting to multiple front-ends (gui, csv, cli). Each implementation of this interface is for each output.

#### Modules
- `Main.cpp` -> Programs entry point
- `TaskRunner.cpp` -> Program director
- `DataQueue.cpp` -> Threadsafe data structure
- `Threadpool.cpp` -> Threadpool implementation for this programs requirements
- `ReaderManager` -> Reads data from DataQueue
- `ExchangeSocket` -> WebSocket calls to fetch data
- `Front` -> Outputs

#### Concurrency
- The `Threadpool` that is created by `TaskRunner` launches each `ExchangeSocket`. These are writers to the `DataQueue`.
- `ReaderManager` is also launched on its own thread, it tries to read from the `DataQueue` and pass it onto each `Front`.

#### Extra
- `trader` component to `autotrade`. (wont make it actually trade for obvious reasons, but can output to cli or gui when an algo wouldve done things e.g. buy from binance, sell on kucoin

