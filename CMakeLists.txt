cmake_minimum_required(VERSION 3.31)
set(TARGET_NAME crypto_aggregator)

project(${TARGET_NAME} VERSION 0.1 DESCRIPTION "Multithreaded Crypto Arbitrage Aggregator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Welcome to Arnavs project: " ${TARGET_NAME})

