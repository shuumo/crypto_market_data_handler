#ifndef DATA_STORE
#define DATA_STORE

#include <unordered_map>
#include <string>
#include <vector>
#include <shared_mutex>

#include "../DataStore/DataPair.hpp"

class DataStore {
private:
    std::unordered_map<std::string, std::vector<DataPair>> map;
    mutable std::shared_mutex map_mutex;

public:
    auto init_symbol_keys(const std::vector<std::string> &key_list,
                          const int count) -> bool; 

    auto write_ask(int id,
                   const std::string& key,
                   const DataPoint& ask) -> bool;

    auto write_bid(int id,
                   const std::string& key,
                   const DataPoint& bid) -> bool;

    auto get_ask(int id,
                 const std::string& key) -> DataPoint;

    auto get_bid(int id,
                 const std::string& key) -> DataPoint;

    auto begin()       -> decltype(map.begin())  { return map.begin(); }
    auto end()         -> decltype(map.end())    { return map.end(); }

    auto begin() const -> decltype(map.begin())  { return map.begin(); }
    auto end()   const -> decltype(map.end())    { return map.end(); }

    auto get_mutex() const -> std::shared_mutex& { return map_mutex; }
};

#endif
