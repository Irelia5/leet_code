#include <unordered_map>
#include <list>

class LRUCache {
    public:
    LRUCache(int capacity) : capacity_(capacity) {}
    int get(int key) {
        auto iter = cache_.find(key);
        if (iter == cache_.end()) return -1;
        touch(iter);
        return iter->second.first;
    }

    void put(int key, int value) {
        auto iter = cache_.find(key);
        if (iter != cache_.end()) touch(iter);
        else {
            if (cache_.size() == capacity_) {
                cache_.erase(used_.back());
                used_.pop_back();
            }
            used_.push_front(key);
        }
        cache_[key] = {value, used_.begin() };
    }

private:
    void touch(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator iter) {
        int key = iter->first;
        used_.erase(iter->second.second);
        used_.push_front(key);
        iter->second.second = used_.begin();
    }
    int capacity_;
    std::list<int> used_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache_;
};