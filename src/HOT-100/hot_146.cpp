/**
-- question: LRU 缓存
-- method:
 - [ ] 哈希表 + 双向链表

--result:

-- analyse:
Time: O( 1 )
Space: O( capacity )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:


private:

    // function end.
};

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;

    DLinkedNode() : key(0), value(0), prev(nullptr), next(prev) {}

    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : size(0), cap(capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;

            if (size > cap) {
                DLinkedNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }

    }

    ~LRUCache(){
        while(cache.size()){
            DLinkedNode* node = removeTail();
            cache.erase(node->key);
            delete node;
            --size;
        }

        delete head;
        delete tail;
    }

private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int cap;

    DLinkedNode *removeTail() {
        DLinkedNode *tmp = tail->prev;
        removeNode(tmp);
        return tmp;
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto lRUCache = std::make_shared<LRUCache>(2);

    lRUCache->put(1, 1);
    lRUCache->put(2, 2);

    IC(lRUCache->get(1), 1);

    lRUCache->put(3, 3);
    IC(lRUCache->get(2), -1);
    lRUCache->put(4, 4);

    IC(lRUCache->get(1), -1);
    IC(lRUCache->get(3), 3);
    IC(lRUCache->get(4), 4);
    // code end

    return 0;
}


