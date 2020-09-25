#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if (cache_hash_.find(key) != cache_hash_.end()) {
            put(key, cache_hash_[key]->second);
            return cache_hash_[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache_hash_.find(key) != cache_hash_.end()) {
            cache_list_.erase(cache_hash_[key]);
        } else if (cache_list_.size() >= capacity_) {
            cache_hash_.erase(cache_list_.back().first);
            cache_list_.pop_back();
        }
        cache_list_.push_front({key, value});
        cache_hash_[key] = cache_list_.begin();
    }

private:
    int capacity_;
    std::list<std::pair<int, int>> cache_list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_hash_;
};