#ifndef DATA_PAIR
#define DATA_PAIR

#include "../DataStore/DataPoint.hpp"
#include <mutex>

class DataPair {
private:
    /*
     * Mutex for the DataPair
     */
    std::mutex data_mutex;

    /*
     * Chrono time of when this data pair was modified last
     */
    int chrono_latest;

    /*
     * DataPoint containing bid data
     */
    DataPoint bid;

    /*
     * DataPoint containing ask data
     */
    DataPoint ask;
public:
    /*
    * Returns true if a valid ask DataPoint exists.
    * False Otherwise.
    */
    bool valid_ask() const;

    /*
    * Returns true if a valid bid DataPoint exists.
    * False Otherwise.
    */
    bool valid_bid() const;

    /*
    * Returns copy of bid DataPoint
    */
    DataPoint getBid() const;

    /*
    * Returns copy of ask DataPoint
    */
    DataPoint getAsk() const;

    /*
    * Sets bid DataPoint with parameter bid
    */
    bool setBid(DataPoint bid);

    /*
    * Sets ask DataPoint with parameter ask
    */
    bool setAsk(DataPoint ask);
};

#endif
