This program is a Crypto Market Data Aggregator, aiming to utilize efficient concurrent programming, websockets and rest api. It will be implemented in C++17, and cmake/makefile for building.

## MVP REQUIREMENTS IN FUNCTIONALITY
1. Fetch real-time data from three cryptocurrency exchanges. (with precise timestamps)
2. Normalize the data
3. Aggregated data outputed to CLI quickly, in real time. also write to csv.
4. auto-trade found arbitrage opportunities (and lose all your money)

## ARCHITECTURE (subject to change a LOT, tryna be modular)
#### Interfaces
- `exchangeSocket` for normalizing data output from different exchanges
- `outputFront` for outputting to multiple front-ends (gui, csv, cli)

#### taskRunner threads
- reader thread for batch-reading from a queue and sending to an outputManager
- outputManager thread for sending to outputFronts, outputFronts can all run on this thread? (e.g. gui)
- writer threads for writing data to a queue. all the writers will be in a threadpool together.

#### Core
- `main` file to launch the program
- `exchangeSocket` implementations e.g. `binanceSocket.cpp` or `kucoinSocket.cpp`. These use websocket api from each exchange to get data and return in a normalized form
- `taskRunner` director class of the program, this class is solely incharge of launching each thread. Maybe merge with main and make `taskRunner` the main?
- `dataQueue` will be queue implementation (lock-free? for learning purposes). This queue will be initialized in taskRunner before launching the reader and writer threads, because the reader and writer will be reading and writing to this queue!
- `outputManager` will be run on its own thread. it will be called to by the reader, so basically the reader will take data from the queue and pass it to the outputManager which will display data. Maybe this can be the reader rather than having a seperate reader as a buffer? Ill have to do some performance testing and drawing to determine.
- `outputFront` implementations for the output manager, so it can just send the data to whatever fronts are enabled e.g. `guiFront`, `csvFront`, `cliFront`.
- `threadPool` will be a thead pool implementation for the `exchangeSocket` writers.

#### Extra
- `trader` component to `autotrade`. (wont make it actually trade for obvious reasons, but can output to cli or gui when an algo wouldve done things e.g. buy from binance, sell on kucoin

