cmake_minimum_required(VERSION 3.31)
set(TARGET_NAME crypto_aggregator)

project(${TARGET_NAME} VERSION 0.1 DESCRIPTION "Multithreaded Crypto Market Data Aggregator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${TARGET_NAME}
    Main.cpp
    Loader/Loader.hpp
    Loader/Loader.cpp
)

message(STATUS "Welcome to Arnavs project: " ${TARGET_NAME})

