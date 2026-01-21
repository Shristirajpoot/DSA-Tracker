#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> cache;

public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        auto it = cache[key];
        int val = it->second;
        dq.erase(it);
        dq.push_front({key, val});
        cache[key] = dq.begin();
        return val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) dq.erase(cache[key]);
        else if (dq.size() == cap) {
            int last = dq.back().first;
            dq.pop_back();
            cache.erase(last);
        }
        dq.push_front({key, value});
        cache[key] = dq.begin();
    }
};
