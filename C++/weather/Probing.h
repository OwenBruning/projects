#ifndef CS124A_HASHING_PROBING_H
#define CS124A_HASHING_PROBING_H

#include <functional>
#include <string>
#include <vector>

template<typename T>
class Probing {
private:
    enum status {empty, active, removed};

    struct hashItem {
        T item;
        status state;
    };

    std::vector<hashItem> hashTable;
    int tableSize;
    int numberOfItems;
    std::function<std::string(const T &)> getKey;

    unsigned int hornerHash(const std::string &key, int newHash) {
        unsigned int hashVal = 0;
        for (char ch : key) {
            hashVal = newHash*hashVal + ch;
        }
        return hashVal % tableSize;
    }

    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

    void rehash(int newHash) {
        // Make a copy of the hash table.
        vector<hashItem> oldTable = hashTable;
        // Resize the hash table.
        hashTable.resize(nextPrime(oldTable.size() * 2));
        // Remove everything from the hash table.
        for (hashItem &h : hashTable) {
            h.state = empty;
        }
        // Update fields.
        tableSize = hashTable.size();
        numberOfItems = 0;
        // Reinsert the active items.
        for (hashItem &h : oldTable) {
            if (h.state == active) {
                insert(h.item, newHash);
            }
        }
    }

public:
    Probing(int tableSizeIn, std::function<std::string(const T &)> getKeyIn) {
        hashTable.resize(tableSizeIn);
        for (hashItem &h : hashTable) {
            h.state = empty;
        }
        tableSize = tableSizeIn;
        getKey = getKeyIn;
        numberOfItems = 0;
    }

    int getSize() const {
        return tableSize;
    }

    void insert(const T &item, int newHash) {
        std::string key = getKey(item);
        // Check to make sure the item is not already in the table.
        T temp;
        if (!search(key, temp, newHash)) {
            int index = hornerHash(key, newHash);
            // Find an empty index to store the item.
            while (hashTable[index].state == active) {
                ++index;
                if (index == tableSize) {
                    // We reached the end of the hash table.
                    // Loop back to the beginning.
                    index = 0;
                }
            }
            hashTable[index].item = item;
            hashTable[index].state = active;
            ++numberOfItems;
            if (numberOfItems > (tableSize / 2.0)) {
                rehash(newHash);
            }
        }
    }

    // Assuming that keys are unique.
    // If we find the hashItem, set item to hashItem and
    // return true. Return false otherwise.
    bool search(std::string key, T &item, int newHash) {
        int index = hornerHash(key, newHash);
        int startingIndex = index;
        reads = 0;
        while (hashTable[index].state != empty) {
            reads++;
            if (hashTable[index].state == active &&
                getKey(hashTable[index].item) == key) {
                // We found the item.
                item = hashTable[index].item;
                return true;
            }
            // The state is removed or
            // it's not the item we're looking for
            ++index;
            if (index == startingIndex){
                // we have made a full loop of the table
                // everything is either active or removed
                // we have not found the item
                return false;
            } else if (index == tableSize) {
                // We reached the end of the hash table.
                // Loop back to the beginning.
                index = 0;
            }
        }
        // item not found in table
        return false;
    }

    bool remove(std::string key, int newHash) {
        int index = hornerHash(key, newHash);
        int startingIndex = index;
        while (hashTable[index].state != empty) {
            if (hashTable[index].state == active &&
                getKey(hashTable[index].item) == key) {
                // We found the item.
                hashTable[index].state = removed;
                --numberOfItems;
                return true;
            }
            // The state is removed or
            // it's not the item we're looking for
            ++index;
            if (index == startingIndex){
                // we have made a full loop of the table
                // everything is either active or removed
                // we have not found the item
                return false;
            } else if (index == tableSize) {
                // We reached the end of the hash table.
                // Loop back to the beginning.
                index = 0;
            }
        }
        // item not found in table
        return false;
    }

    void printTable(std::ostream &outs) const {
        for (int i = 0; i < tableSize; ++i) {
            outs << i << ": ";
            if (hashTable[i].state == active) {
                outs << hashTable[i].item;
            }
            outs << endl;
        }
    }

};

#endif //CS124A_HASHING_PROBING_H
