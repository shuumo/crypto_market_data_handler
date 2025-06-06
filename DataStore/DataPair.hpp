#ifndef DATA_PAIR
#define DATA_PAIR

#include "../DataStore/DataPoint.hpp"
//#include <mutex>
#include <atomic>

class DataPair {
private:
    /*
     * Mutex for the DataPair
     */
    //std::mutex data_mutex;

    /*
     * Atomic Flag
     */
    std::atomic<bool> lock = {0};


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
    * Returns true if a valid ask exists.
    * False Otherwise.
    */
    bool valid_ask() const;

    /*
    * Returns true if a valid bid exists.
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
    * Returns a reference to the mutex of the class
    */
    //std::mutex& getMutex();

    /*
     * Assumes lock is free on first try and tries to lock, 
     * If its not free, wait for lock to be released
     *
     * Needs modification for arm, currently uses an x86 instruction.
     */
    void lock_atomic_flag() noexcept;

    /*
     * Checks if lock is free
     */
    bool try_atomic_flag() noexcept;

    /*
     * Unlocks the atomic if held
     */
    void unlock_atomic_flag() noexcept;

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
