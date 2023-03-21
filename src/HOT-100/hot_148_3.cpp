/**
-- question: 排序链表
-- method:
 - [ ] sort, create
 - [ ] 自顶向下归并排序
 - [*] 自底向上归并排序

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return head;
        int length = 0;
        ListNode *node = head;
        while (node) {
            ++length;
            node = node->next;
        }

        ListNode *dummyNode = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            IC(subLength);

            ListNode *prev = dummyNode, *curr = dummyNode->next;
            while (curr) {
                ListNode *node1 = curr;
                for (int i = 1; i < subLength && curr->next; i++) curr = curr->next;

                ListNode *node2 = curr->next;
                curr->next = nullptr;
                curr = node2;
                for (int i = 1; i < subLength && curr && curr->next; i++) curr = curr->next;
                ListNode *next = nullptr;
                if (curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode *merged = merge(node1, node2);
                prev->next = merged;
                while (prev->next) {
                    prev = prev->next;
                }
                curr = next;
            }
        }

        node = dummyNode->next;
        delete dummyNode;
        return node;
    }


    ListNode *sortList_2(ListNode *head) {
        if (!head) return head;
        int length = 0;
        ListNode *cur = head;
        while (cur) {
            ++length;
            cur = cur->next;
        }

        ListNode *dummyNode = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode *prev = dummyNode, *curr = dummyNode->next;
            while (curr) {
                ListNode *part1 = curr;
                for (int i = 1; i < subLength && curr->next; i++) curr = curr->next;

                ListNode *part2 = curr->next;
                curr->next = nullptr;
                curr = part2;
                for (int i = 1; i < subLength && curr && curr->next; i++) curr = curr->next;
                ListNode *next = nullptr;
                if (curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }

                prev->next = merge(part1, part2);
                while (prev->next) {
                    prev = prev->next;
                }
                curr = next;
            }

        }

        cur = dummyNode->next;
        delete dummyNode;
        return cur;
    }

private:
    static ListNode *merge(ListNode *node1, ListNode *node2) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *cur = dummyNode;
        while (node1 && node2) {
            if (node1->val <= node2->val) {
                cur->next = node1;
                node1 = node1->next;
            } else {
                cur->next = node2;
                node2 = node2->next;
            }
            cur = cur->next;
        }
        if (node1) cur->next = node1;
        else cur->next = node2;

        cur = dummyNode->next;
        delete dummyNode;
        return cur;
    }



    // function end.
};


int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> head = {4, 2, 1, 3, 5, 6, 3, 6, 3, 2};
    vector<int> rel = {1, 2, 3, 4};

    IC(head, rel);

    auto headL = vecT2ListNode(head);
//    auto result = solution->sortList(headL);
    // auto result = sortList(headL);
    auto result = solution->sortList_2(headL);

    outListNode(result);

//    deleteListNode(headL);

    deleteListNode(result);
    // code end

    return 0;
}
