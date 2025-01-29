This program is a Crypto Market Data Aggregator, aiming to utilize efficient concurrent programming, websockets and rest api. It will be implemented in C++17, and cmake/makefile for building.

## MVP REQUIREMENTS IN FUNCTIONALITY
1. Fetch real-time data from three cryptocurrency exchanges. (Best bid price, Best ask price, Exchange name, Precise timestamp)
2. Normalize the data
3. Output to CLI quickly, in real time. (The best bid and ask prices across all exchanges and which exchange has the best bid/ask)


## ADDITIONAL FEATURES TO ADD AFTER MVP
1. Gui Dashboard using QT6 for real time data.
2. CSV export
3. Fetch More Data (Full Order Book)
