class LRUCache {
public:
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>> ::iterator> cache;
    int cacheSize;
    
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        dll.splice(dll.begin(), dll, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            dll.splice(dll.begin(), dll, cache[key]);
            cache[key]->second = value;
            return;
        }
        
        if(cache.size() == cacheSize) {
            auto deleteKey = dll.back().first;
            dll.pop_back();
            cache.erase(deleteKey);
        }
        
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */