#include "DataStore.hpp"
#include "../Core/AtomicGuard.hpp"
#include <mutex>

auto DataStore::init_symbol_keys(const std::vector<std::string> &key_list,
                                 const int count) -> bool {
    auto lock = std::unique_lock{map_mutex};
    if(key_list.empty()) return false;
    for(const auto& i: key_list) {
        map[i] = std::vector<DataPair>(count);
    }
    return true;
}

auto DataStore::write_ask(int id,
                          const std::string& key,
                          const DataPoint& ask) -> bool {
    auto lock = std::shared_lock{map_mutex};
    try {
        auto& pair_vec = map.at(key);
        if(static_cast<size_t>(id) >= pair_vec.size()) return false;
        auto guard = AtomicGuard{pair_vec[id]};
        pair_vec[id].setAsk(ask);
        return true;
    } catch(...) { return false; }
}

auto DataStore::write_bid(int id,
                          const std::string& key,
                          const DataPoint& bid) -> bool {
    auto lock = std::shared_lock{map_mutex};
    try {
        auto& pair_vec = map.at(key);
        if(static_cast<size_t>(id) >= pair_vec.size()) return false;
        auto guard = AtomicGuard{pair_vec[id]};
        pair_vec[id].setBid(bid);
        return true;
    } catch(...) { return false; }
}

auto DataStore::get_ask(int id,
                        const std::string& key) -> DataPoint {
    auto lock = std::shared_lock{map_mutex};
    try {
        auto& pair_vec = map.at(key);
        if(static_cast<size_t>(id) >= pair_vec.size()) return {};
        auto guard = AtomicGuard{pair_vec[id]};
        return pair_vec[id].getAsk();
    } catch(...) { return {}; }
}

auto DataStore::get_bid(int id,
                        const std::string& key) -> DataPoint {
    auto lock = std::shared_lock{map_mutex};
    try {
        auto& pair_vec = map.at(key);
        if(static_cast<size_t>(id) >= pair_vec.size()) return {};
        auto guard = AtomicGuard{pair_vec[id]};
        return pair_vec[id].getBid();
    } catch(...) { return {}; }
}
