// Design a HashMap without using any built-in hash table libraries. Implement the MyHashMap class:

//     1 - MyHashMap() initializes the object with an empty map.
//     2 - void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
//     3 - int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
//     4 - void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.





#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* next;

    Node(int k = -1, int v = -1, Node* n = nullptr) : key(k), val(v), next(n) {}
};

class MyHashMap {
private:
    vector<Node*> map;

public:
    MyHashMap() {
        map.resize(1000);
        for (int i = 0; i < 1000; ++i) {
            map[i] = new Node();
        }
    }

    int hash(int key) {
        return key % 1000;
    }

    void put(int key, int value) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];

        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }

        cur->next = new Node(key, value);
    }

    int get(int key) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];

        while (cur->next) {
            if (cur->next->key == key) {
                return cur->next->val;
            }
            cur = cur->next;
        }

        return -1;
    }

    void remove(int key) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];

        while (cur->next) {
            if (cur->next->key == key) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
    }
};

int main(){
    MyHashMap* hashMap = new MyHashMap();
    hashMap->put(1, 1);
    hashMap->put(2, 2);
    cout << hashMap->get(1) << endl;
    cout << hashMap->get(3) << endl;
    hashMap->put(2, 1);
    cout << hashMap->get(2) << endl;
    hashMap->remove(2);
    cout << hashMap->get(2) << endl;
    delete hashMap;
    return 0;
}