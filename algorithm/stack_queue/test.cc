#include <unordered_map>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
class LRUCache {
public:
    int num;
    int m_capacity;
    unordered_map<int, int> tmp_map;
    list<int> tmp_list;
public:
    LRUCache(int capacity) :num(0) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        auto iter = tmp_map.find(key);
        if(iter == tmp_map.end()){
            return -1;
        } else {
            auto qu_iter = find(tmp_list.begin(), tmp_list.end(), key);
            tmp_list.erase(qu_iter);
            tmp_list.push_back(key);
            return iter->second;
        }
    }
    
    void put(int key, int value) {
        auto iter = tmp_map.find(key);
        if(iter == tmp_map.end()){
            if(num == m_capacity){
                tmp_map.erase(tmp_map.find(tmp_list.front()));
                tmp_list.pop_front();
                tmp_list.push_back(key);
                tmp_map[key] = value;
            } else {
                tmp_list.push_back(key);
                tmp_map[key] = value;
                num++;
            }
        } else {
            if(num == m_capacity){
                auto qu_iter = find(tmp_list.begin(), tmp_list.end(), key);
                tmp_list.erase(qu_iter);   
            } else {
                num ++;
            }
            tmp_list.push_back(key);
            tmp_map[key] = value;
        }
    }
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl;      // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    std::cout << cache.get(2) << std::endl;;       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    std::cout << cache.get(1) << std::endl;     // 返回 -1 (未找到)
    std::cout << cache.get(3) << std::endl;       // 返回  3
    std::cout << cache.get(4) << std::endl;       // 返回  4
}