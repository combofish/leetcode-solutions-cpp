/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.

    // function end.
};


class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    int get(int index) {
        if (index > (_size - 1) || index < 0)
            return -1;

        LinkedNode *cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    };

    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        ++_size;
    }

    void addAtTail(int val) {
        auto newNode = new LinkedNode(val);
        auto cur = _dummyHead;
        while (cur->next != nullptr)
            cur = cur->next;

        cur->next = newNode;
        ++_size;
    }

    void addAtIndex(int idx, int val) {
        if (idx < 0 || idx > _size)
            return;

        auto newNode = new LinkedNode(val);
        auto cur = _dummyHead;
        while (idx--)
            cur = cur->next;

        newNode->next = cur->next;
        cur->next = newNode;
        ++_size;
    }
    void deleteAtIndex(int idx) {
        if (idx < 0 || idx >= _size)
            return;

        auto cur = _dummyHead;
        while (idx--)
            cur = cur->next;

        auto tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        --_size;
    }

    void printLinkedList() {
        cout << "Now LinkedList is: [ ";

        auto cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << "]" << endl;
    }

    ~MyLinkedList() {
        auto cur = _dummyHead;
        while (cur->next != nullptr) {
            auto tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }

        delete _dummyHead;
    }

private:
    int _size;
    LinkedNode *_dummyHead;
};

int main() {

    auto solution = new Solution();

    // code start


    auto linkedList = new MyLinkedList();
    linkedList->printLinkedList();
    linkedList->addAtHead(1);
    linkedList->printLinkedList();
    linkedList->addAtTail(3);
    linkedList->printLinkedList();
    linkedList->addAtIndex(1, 2);
    linkedList->printLinkedList();


    IC(linkedList->get(1));
    linkedList->printLinkedList();

    linkedList->deleteAtIndex(1);
    linkedList->printLinkedList();

    IC(linkedList->get(1));
    linkedList->printLinkedList();

    delete linkedList;
    // code end

    delete solution;
    return 0;
}
