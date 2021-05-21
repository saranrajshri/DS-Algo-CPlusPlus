#include "bits/stdc++.h"
#define int long long
using namespace std;

class LRUCache {
public:
	list<pair<int, int>> dll;
	unordered_map<int, list<pair<int, int>> ::iterator> cache;
	int capacity;

    LRUCache(int x) {
		capacity = x;	
    }
    
    int get(int key) {
        if(cache.find(key) == m.end()) return -1;

        dll.splice(dll.begin(), dll, cache[key]);

        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != m.end()) {
        	dll.splice(dll.begin(), dll.end(), cache[key]);
        	cache[key]->second = value;
        	return;
        }else{
        	if(cache.size() == capacity) {
        		auto deleteKey = dll.back().first;
        		cache.erase(deleteKey);
        		dll.pop_back();
        	}
        	dll.push_front({key, value});
        	cache[key] = dll.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int32_t main() {
	return 0;	
}
