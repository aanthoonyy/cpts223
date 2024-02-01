/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>
#include "math.h"

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    //vector<pair<pair<K, V>, EntryState>> oldArray;
    vector<list<pair<K, V>>> theLists;
    int currentSize;
public:
    ChainingHash(int n = 11) : theLists(n) , currentSize(0){

    }

    ~ChainingHash() {
        this->clear();
    }

    bool empty() {
        return currentSize == 0;
    }

    int size() {
        return currentSize;
    }

    V& at(const K& key) { 
        int currentPos = hash(key);
        auto& list = theLists[currentPos];
        for (auto& pair : list) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not in hash");
    }




    V& operator[](const K& key) {
        at(key);
    }

    int count(const K& key) {
    }

    void emplace(K key, V value) {
        std::pair<K, V> temp;
        temp.first = key;
        temp.second = value;
        insert(temp);
    }

    void insert(const std::pair<K, V>& pair) {
        auto & whichList = theLists[ hash( pair.first ) ];
        for (auto& p : whichList) {
            if (p.first == pair.first) {
                return;
            }
        }
        whichList.push_back(pair);

        if( ++currentSize > theLists.size( ) )
        {
            rehash();
        }


    }

    void erase(const K& key) {
        for (int i = 0; i < theLists.size(); i++) {
            for (auto j = theLists[i].begin(); j != theLists[i].end(); ) {
                if (j->first == key) {
                    j = theLists[i].erase(j);
                    --currentSize;
                } else {
                    ++j;
                }
            }
        }
    }


    void clear() {
        for (int i = 0; i < theLists.size();i++)
        {
            theLists[i].clear();
        }
        
    }

    int bucket_count() {
        theLists.size();
    }

    int bucket_size(int n) {
        theLists[n].size();
    }

    int bucket(const K& key) {
        for (int i = 0; i < theLists.size();i++)
        {
            auto &linkedList = theLists[i];
            for (auto j = linkedList.begin(); j != linkedList.end(); j++)
            {
                if (j->first == key)
                {
                    return i;
                }
           }    
        }
        return -1;
    }

    float load_factor() {
        return static_cast<float>(currentSize) / theLists.size();
    }

    void rehash() {
        vector<list<pair<K, V>>> oldList = theLists;
        // Create new double-sized, empty table
        theLists.resize( findNextPrime( 2 * theLists.size( ) ) );
        for( auto & thisList : theLists )
            thisList.clear( );

            // Copy table over
        currentSize = 0;
        for( auto & thisList : oldList )
            for( auto & x : thisList )
                insert( std::move( x ) );

        oldList.clear();
    }

    void rehash(int n) {
        vector<list<pair<K, V>>> oldList = theLists;
        // Create new double-sized, empty table
        theLists.resize( findNextPrime( 2 * n ) );
        for( auto & thisList : theLists )
            thisList.clear( );

            // Copy table over
        currentSize = 0;
        for( auto & thisList : oldList )
            for( auto & x : thisList )
                insert( std::move( x ) );

        oldList.clear();
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
        return static_cast<int>(key) % theLists.size();       
    }

};

#endif //__CHAINING_HASH_H
