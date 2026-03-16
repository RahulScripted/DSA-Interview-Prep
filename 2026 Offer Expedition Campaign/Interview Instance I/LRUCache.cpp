// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache. Implement the LRUCache class:

//     1 - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//     2 - int get(int key) Return the value of the key if the key exists, otherwise return -1.
//     3 - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
//     4 - The functions get and put must each run in O(1) average time complexity.






#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> accessOrder;

public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        accessOrder.erase(cache[key].second);
        accessOrder.push_front(key);
        cache[key].second = accessOrder.begin();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            accessOrder.erase(cache[key].second);
            cache[key] = {value, accessOrder.insert(accessOrder.begin(), key)};
        } else {
            if (cache.size() == capacity) {
                int lruKey = accessOrder.back();
                accessOrder.pop_back();
                cache.erase(lruKey);
            }
            cache[key] = {value, accessOrder.insert(accessOrder.begin(), key)};
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl; 
    cache.put(4, 4);
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
}