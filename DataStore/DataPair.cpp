#include "DataPair.hpp" 

std::mutex& DataPair::getMutex() {
    return data_mutex;
}

DataPoint DataPair::getAsk() const {
    return ask;
}

DataPoint DataPair::getBid() const {
    return bid;
}

bool DataPair::setAsk(DataPoint ask) {
    this->ask = ask;
    return true;
}

bool DataPair::setBid(DataPoint bid) {
    this->bid = bid;
    return true;
}

