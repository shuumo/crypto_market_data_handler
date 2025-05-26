#ifndef DATA_STORE
#define DATA_STORE

#include <unordered_map>
#include <string>
#include <vector>

#include "../DataStore/DataPair.hpp"

class DataStore {
private:
    /*
     * symbol -> exchange via index id -> DataPair(bid-ask)
     */
    std::unordered_map<std::string, std::vector<DataPair>> map;

public:
    /*
     * Takes a string vector of keys and creates
     * each key pair for symbols and its list of exchanges.
     * Returns 1 on success, 0 on fail.
     */
    bool init_symbol_keys(std::vector<std::string> &key_list, const int count); 

    /*
    * Replace ask DataPoint for spesific exchange (id) and symbol (key)'s DataPair
    * Returns true on success, false on fail.
    */
    bool write_ask(int id, std::string key, DataPoint ask);

    /*
    * Replace bid DataPoint for spesific exchange (id) and symbol (key)'s DataPair
    * Returns true on success, false on fail.
    */
    bool write_bid(int id, std::string key, DataPoint bid);

    /*
     * Returns a copy of a ask DataPoint for spesific exchange (id) and symbol (key)'s DataPair
     */
    DataPoint get_ask(int id, std::string key);

    /*
     * Returns a copy of a bid DataPoint for spesific exchange (id) and symbol (key)'s DataPair
     */
    DataPoint get_bid(int id, std::string key);

    /*
    * Iterator overloads
    */
    auto begin()       -> decltype(map.begin())  { return map.begin(); }
    auto end()         -> decltype(map.end())    { return map.end(); }

    auto begin() const -> decltype(map.begin())  { return map.begin(); }
    auto end()   const -> decltype(map.end())    { return map.end(); }

    auto cbegin() const -> decltype(map.cbegin()) { return map.cbegin(); }
    auto cend()   const -> decltype(map.cend())   { return map.cend(); }


};

#endif
