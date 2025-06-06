#include "DataStore.hpp"
#include "../Core/AtomicGuard.hpp"

bool DataStore::init_symbol_keys(std::vector<std::string> &key_list, const int count)  {
    if(key_list.empty()) return false;
    for(const auto& i: key_list) {
        map[i] = std::vector<DataPair>(count);
    }
    return true;
}

bool DataStore::write_ask(int id, std::string key, DataPoint ask) {
    //std::lock_guard<std::mutex> guard(map[key][id].getMutex());
    AtomicGuard guard(map[key][id]);
    map[key][id].setAsk(ask);
    return true;
}

bool DataStore::write_bid(int id, std::string key, DataPoint bid) {
    //std::lock_guard<std::mutex> guard(map[key][id].getMutex());
    AtomicGuard guard(map[key][id]);
    map[key][id].setBid(bid);
    return true;
}

DataPoint DataStore::get_ask(int id, std::string key) {
    //std::lock_guard<std::mutex> guard(map[key][id].getMutex());
    AtomicGuard guard(map[key][id]);
    return map[key][id].getAsk();
}

DataPoint DataStore::get_bid(int id, std::string key) {
    //std::lock_guard<std::mutex> guard(map[key][id].getMutex());
    AtomicGuard guard(map[key][id]);
    return map[key][id].getBid();
}
