#include "DataStore.hpp"

bool DataStore::init_keys(std::vector<std::string> &key_list) {
    if(key_list.empty()) return false;
    for(const auto& i: key_list) {
        map[i];
    }
    return true;
}

