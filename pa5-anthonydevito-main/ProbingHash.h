#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"


using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
// enum EntryState {
//     EMPTY = 0,
//     VALID = 1,
//     DELETED = 2
// };

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    // Needs a table and a size.
    int currentSize;
    vector<pair<pair<K, V>, EntryState>> tableVec;
    // Table should be a vector of std::pairs for lazy deletion

public:
    ProbingHash(int n = 11) : tableVec(n), currentSize(0) {
        for (auto & entry : tableVec)
            entry.second = EMPTY;
    }

    ~ProbingHash() {
        // Needs to actually free all table contents
        clear();
    }

    bool empty() {
        if (currentSize == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int size() {
        return currentSize;
    }

    V& at(const K& key) {
        int currentPos = 0;
        if (tableVec[currentPos].second == VALID && tableVec[currentPos].first.first == key) {
            return tableVec[currentPos].first.second;

         }
        throw std::out_of_range("Key not in hash");
    }

    V& operator[](const K& key) {
        at(key);
    }

    int count(const K& key) {
        return 1;
    }

    void emplace(K key, V value) {

        std::pair<K, V> temp;
        temp.first = key;
        temp.second = value;
        insert(temp);
        
    }

    void insert(const std::pair<K, V> &pair) {
        // Insert x as active



        auto currentPos = findPos( pair );
            
        if( isActive( currentPos ) )
            return;
        
        if( tableVec[ currentPos ].second != DELETED )
            ++currentSize;

        tableVec[ currentPos ].first = pair;
        tableVec[ currentPos ].second = VALID;

        // Rehash; see Section 5.5
        auto load = load_factor();
        if (load >= 0.75){
            rehash( );
        }

        //return true;
    }

    void erase(const K& key) {

    for (int i = 0; i < tableVec.size();i++)
    {
        if (tableVec[i].second == VALID && tableVec[i].first.first == key) {
            tableVec[i].second = DELETED;
            --currentSize;
        }  
    }
        }

    void clear() {
        currentSize = 0;
        for( auto & entry : tableVec )  
        entry.second = EMPTY;
    }

    int bucket_count() {
        return tableVec.size();
    }

    int bucket_size(int n) {
        //return if empty or full
        if (tableVec[n].second == EMPTY)
        {
            return EMPTY;
        }
        else{
            return VALID;
        }
    }

    int bucket(const K& key) {
        //given a key tell which bucket it is
        for (auto i = 0; i < tableVec.size(); i++)
        {
            if (tableVec[i].first.first == key)
            {
                if (tableVec[i].second == DELETED)
                {
                    return -1;
                }
                return i;
            }
            
        }
        return -1;
        
    }

    float load_factor() {
        return static_cast<float>(currentSize) / tableVec.size();
    }

    void rehash()
    {
        vector<pair<pair<K, V>, EntryState>> oldArray = tableVec;
        
            // Create new double-sized, empty table
        tableVec.resize( findNextPrime( 2 * oldArray.size( ) ) );
        //tableVec.resize( findNextPrime( n ) );
        for (auto i = 0; i < tableVec.size(); i++) {
            //entry.info = EMPTY;
            tableVec[i].second = EMPTY;
        }
            // Copy table over
        currentSize = 0;
        for (auto i = 0; i < oldArray.size(); i++) {
            if (oldArray[i].second == VALID) {
                auto currentPos = findPos(oldArray[i].first);
                tableVec[currentPos] = oldArray[i];
                currentSize++;
            }
}

    }

    void rehash(int n) {
        //vector<EntryState> oldArray = tableVec;
        vector<pair<pair<K, V>, EntryState>> oldArray = tableVec;
        
            // Create new double-sized, empty table
        //tableVec.resize( findNextPrime( 2 * oldArray.size( ) ) );
        tableVec.resize( findNextPrime( n ) );
        for (auto i = 0; i < tableVec.size(); i++) {
            //entry.info = EMPTY;
            tableVec[i].second = EMPTY;
        }
            // Copy table over
        currentSize = 0;
        for (auto i = 0; i < oldArray.size(); i++) {
            if( tableVec[i].second == VALID )
                insert( std::move( tableVec[i].first ) );
        } 
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {

        return 0;       
    }

    bool isActive( int currentPos ) const
      { return tableVec[ currentPos ].second == VALID; }

    
    int findPos( const std::pair<K, V>& pair ) const
    //int findPos(const K& key) const
    {
        auto tableSize = tableVec.size();
    int currentPos = static_cast<int>(pair.first) %  tableSize;
    int offset = 1;

    while( tableVec[currentPos].second != EMPTY && tableVec[currentPos].first.first != pair.first )
    {
        currentPos += offset;  // Linear probing
        if(currentPos >= tableVec.size())
            currentPos -= tableVec.size();
    }

    return currentPos;
}

    
};

#endif //__PROBING_HASH_H
