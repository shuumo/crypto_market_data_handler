cmake_minimum_required(VERSION 3.30)
set(TARGET_NAME crypto_aggregator)

project(${TARGET_NAME} VERSION 0.1 DESCRIPTION "Multithreaded Crypto Market Data Aggregator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required libraries
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)

# Target files
add_executable(${TARGET_NAME}
    Main.cpp
    Core/TaskRunner.hpp
    Core/TaskRunner.cpp
    Loader/Loader.hpp
    Loader/Loader.cpp
    DataStore/DataPair.hpp
    DataStore/DataPair.cpp
    DataStore/DataPoint.hpp
    DataStore/NoAtomicDataPair.hpp
    DataStore/DataStore.hpp
    DataStore/DataStore.cpp
    ExchangeSocket/IExchangeSocket.hpp
    ExchangeSocket/BinanceSocket.cpp
    ExchangeSocket/TestSocket.cpp
    Front/IFront.hpp
    Front/CliFront.cpp
    Front/ReaderManager.hpp
    Front/ReaderManager.cpp
)

# Linked libraries
target_link_libraries(${TARGET_NAME}
    PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
    Boost::boost
    nlohmann_json::nlohmann_json
    pthread
)

message(STATUS "Welcome to Arnavs project: " ${TARGET_NAME})

