cmake_minimum_required(VERSION 3.31)
set(TARGET_NAME crypto_aggregator)

project(${TARGET_NAME} VERSION 0.1 DESCRIPTION "Multithreaded Crypto Market Data Aggregator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${TARGET_NAME}
    Main.cpp
    Core/TaskRunner.hpp
    Core/TaskRunner.cpp
    Loader/Loader.hpp
    Loader/Loader.cpp
    DataStore/DataPair.hpp
    DataStore/DataPair.cpp
    DataStore/DataPoint.hpp
    DataStore/DataStore.hpp
    DataStore/DataStore.cpp
    ExchangeSocket/IExchangeSocket.hpp
)

message(STATUS "Welcome to Arnavs project: " ${TARGET_NAME})

