#ifndef CS124A_HASHING_SEPARATECHAINING_H
#define CS124A_HASHING_SEPARATECHAINING_H

#include <functional>
#include <string>
#include <vector>
#include "StationData.h"

//template<typename T>
class SeparateChaining {
private:
    std::vector<std::vector<StationData>> hashTable;
    int tableSize;
    std::function<std::string(const StationData &)> getKey;

    unsigned int hornerHash(const std::string &key, int newHash) {
        unsigned int hashVal = 0;
        for (char ch : key) {
            hashVal = newHash*hashVal + ch; //37 to 30
        }
        return hashVal % tableSize;
    }

public:
    SeparateChaining(int tableSizeIn, std::function<std::string(const StationData &)> getKeyIn) {
        hashTable.resize(tableSizeIn);
        for (std::vector<StationData> &vec : hashTable) {
            vec.clear();
        }
        tableSize = tableSizeIn;
        getKey = getKeyIn;
    }

    void insert(const StationData &item, int newHash) {
        std::string key = getKey(item);
        StationData dummy;
        // Check if the item is already in the hashTable
        if (!search(key, dummy, newHash)) {
            // Item is not there. Insert it.
            int index = hornerHash(key, newHash);
            hashTable[index].push_back(item);
        }
        // Item is in hashTable. Do nothing.
    }

    // Assuming that keys are unique
    // if key leads to active hashItem, set item to hashItem and
    // return true. return false otherwise.

    bool search(std::string key, StationData &item, int newHash) {
        int index = hornerHash(key, newHash);
        reads = 0;
        for (StationData &hashItem : hashTable[index]) {
            reads++;
            if (getKey(hashItem) == key) {
                // we found the item
                item = hashItem;
                return true;
            }
        }
        // went through the vector and didn't find the item
        return false;
    }

    bool remove(std::string key, int newHash) {
        int index = hornerHash(key, newHash);
        for (int i = 0; i < hashTable[index].size(); ++i) {
            if (getKey(hashTable[index][i]) == key) {
                // We found the item. Remove it.
                // Erase method takes an iterator argument
                // Begin method returns iterator that is positioned at
                // the first index. Can add indexes from there.
                hashTable[index].erase(hashTable[index].begin() + i);
                return true;
            }
        }
        // went through the vector and didn't find the item
        return false;
    }

    void printTable(std::ostream &outs) const {
        for (int index = 0; index < tableSize; ++index) {
            outs << index << ": ";
            for (int i = 0; i < hashTable[index].size(); ++i) {
                outs << hashTable[index][i];
                outs << ", "; //if this was one line above, error
            }
            outs << endl;
        }
    }

};

#endif //CS124A_HASHING_SEPARATECHAINING_H
