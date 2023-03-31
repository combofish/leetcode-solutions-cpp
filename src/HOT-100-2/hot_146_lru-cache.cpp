/**
-- question: LRU 缓存
-- method:
 - []

--result:

-- analyse:
Time: O(1)
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
    DLinkedNode *prev, *next;

    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        auto node = cache[key];

        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            auto node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            auto node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;

            if (size > cap) {
                auto tmp = removeTail();
                cache.erase(tmp->key);
                delete tmp;
                --size;
            }
        }
    }

    ~LRUCache() {
        while(size){
            auto tmp = removeTail();
            delete tmp;
            --size;
        }

        delete head;
        delete tail;
    }

private:

    int cap;
    int size;
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head, *tail;

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DLinkedNode *removeTail() {
        auto tmp = tail->prev;
        removeNode(tmp);
        return tmp;
    }

    void addToHead(DLinkedNode *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }
};


int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<string> inputs = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    string args = "[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]";


    string ans = "[null, null, null, 1, null, -1, null, -1, 3, 4]";

    IC(inputs, args, ans);

    auto lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);
    lRUCache->put(2, 2);
    IC(lRUCache->get(1));
    lRUCache->put(3, 3);
    IC(lRUCache->get(2));

    lRUCache->put(4, 4);
    IC(lRUCache->get(1));
    IC(lRUCache->get(3));
    IC(lRUCache->get(4));

    delete lRUCache;

    // code end

    return 0;
}


