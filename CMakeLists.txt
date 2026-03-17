cmake_minimum_required(VERSION 3.30)
set(TARGET_NAME crypto_aggregator)

project(${TARGET_NAME} VERSION 0.1 DESCRIPTION "Multithreaded Crypto Market Data Aggregator")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required libraries
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(websocketpp REQUIRED)

# Target files
# We exclude .cpp files that are included elsewhere to avoid multiple definition errors
add_executable(${TARGET_NAME}
    Main.cpp
    Core/TaskRunner.cpp
    Loader/Loader.cpp
    DataStore/DataPair.cpp
    DataStore/DataStore.cpp
    Front/ReaderManager.cpp
)

# Linked libraries
target_link_libraries(${TARGET_NAME}
    PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
    Boost::boost
    nlohmann_json::nlohmann_json
    websocketpp::websocketpp
    pthread
)

message(STATUS "Welcome to Arnavs project: " ${TARGET_NAME})
