#ifndef DATA_STORE
#define DATA_STORE

#include <unordered_map>
#include <string>
#include "../DataStore/DataPair.hpp"
#include <vector>

class DataStore {
private:
    std::unordered_map<std::string, DataPair> map;

public:
    /*
     * Takes a string vector of keys and creates
     * each key pair.
     * Returns 1 on success, 0 on fail.
     */
    bool init_keys(std::vector<std::string> &key_list); 

    /*
    * Replace ask DataPoint for spesific key's DataPair
    * Returns 1 on success, 0 on fail.
    */
    bool write_ask(std::string key, DataPoint);

    /*
    * Replace bid DataPoint for spesific key's DataPair
    * Returns 1 on success, 0 on fail.
    */
    bool write_bid(std::string key, DataPoint);

    /*
    * read ask DataPoint for spesific key's DataPair
    */
    DataPoint read_bid(std::string key) const;

    /*
    * read bid DataPoint for spesific key's DataPair
    */
    DataPoint read_ask(std::string key) const;
 
    /*
    * Returns list of data_pairs in order (ask - bid) in a vector
    * e.g. start BTCUSDT LTCUSDT end
    */
    std::vector<DataPair> get_full_list() const; 

};

#endif
