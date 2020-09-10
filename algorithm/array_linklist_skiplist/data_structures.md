## 数组
### 实现
物理存储，内存连续一片空间
参照C语言数组或C++ vector
```cpp
    int array[3] = {};
```

### 特性
时间复杂度
* prepend           O(?)
* append            O(1)
* look up(index)    O(1)  
* insert            O(n)
* delete            O(n)

在进行增加元素的操作中，可能超过数组容量，此时需要进行拷贝。

## 链表
物理存储：非连续
实现：
```cpp
//单链表结点的简单定义
class LinkNode {
  public:
    LinkNode(int value) : val_(val), next_(nullptr) {}
  private:
    int val_;
    LinkNode* next_;
};
```
### 特性
时间复杂度
* prepend           O(1)
* append            O(1)
* look up(index)    O(n)  
* insert            O(1)
* delete            O(1)

在现实的应用场景中，按索引查找并不常见，更加常见的是按值查询——kv类型
在这些场景中，需要大量的查找、增加、删除、修改，使用数组结构效率较低，使用链表结点类型更加合理。（增删改都在查的基础上）
时间复杂度均为O(n)

## 跳表
跳表是基于链表缺陷的优化，链表随机存取时间复杂度为O(n)，跳表以空间换时间，降低时间复杂度。
原理上跳表可以无序，按索引随机存取。但在实际应用中几乎是按值查询，这就必然将跳表设计为有序。
再进行跳跃的索引，就形成跳表。

[跳表思想](https://lotabout.me/2018/skip-list/)
[redis跳表](https://redisbook.readthedocs.io/en/latest/internal-datastruct/skiplist.html)
[跳表C++实现](https://blog.csdn.net/weixin_44387066/article/details/90766034)

### 特性
look up
空间复杂度: O(2n) -> O(n)
时间复杂度：O(n) -> O(log2n)

