#include <unordered_map>
#include <list>
#include <iostream>

//LRU分情况讨论
//1. put 已有 2.put 无 3. get 有 4.get 无

struct Node {
    int key;
    int value;
    Node* pre;
    Node* next;
    Node() : key(0), value(0), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), count_(0) , head(new Node()), tail(new Node()) {
        head->pre = nullptr;
        head->next = tail;
        tail->pre = head;
        tail->next = nullptr;
    }
    ~LRUCache() {
        delete head;
        delete tail;
    }
    
    int get(int key) {
        if (hash_.find(key) != hash_.end()) {
            Node* node = hash_[key];
            detach_node(node);
            insert_front_node(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (hash_.find(key) != hash_.end()) {
            Node* node = hash_[key];
            detach_node(node);
            node->value = value;
            insert_front_node(node);
        } else {
            if (count_ >= capacity_) {
                remove_back_node();
            }
            Node* node = new Node();
            node->key = key;
            node->value = value;
            insert_front_node(node);
            hash_[key] = node;
            count_++;
        }
    }

    void detach_node(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void insert_front_node(Node* node) {
       node->next = head->next;
       node->pre = head;
       head->next = node;
       node->next->pre = node;
    }

    void remove_back_node() {
        Node* node = tail->pre;
        hash_.erase(node->key);
        node->pre->next = tail;
        tail->pre = node->pre;
        delete node;
        count_--;
    }

private:
    int capacity_;
    int count_;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> hash_;
};

//["LRUCache","put","put","get","put","get","put","get","get","get"]
//[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
int main()
{
    LRUCache cache(2);
    std::cout << "here1" << std::endl;
    cache.put(1,1);
    std::cout << "here2" << std::endl;
    cache.put(2,2);
    std::cout << "here3" << std::endl;
    std::cout << cache.get(1) << std::endl;
    std::cout << "here4" << std::endl;
    cache.put(3,3);
    std::cout << cache.get(2) << std::endl;
    cache.put(4,4);
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;

}