/**
-- question:
-- method:
 - [ ] 排序链表

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:


    ListNode *sortList(ListNode *head) {
        if (!head) return nullptr;
        int n = 0;
        auto cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }

        auto dummyNode = new ListNode(0);
        dummyNode->next = head;

        for (int subLen = 1; subLen < n; subLen <<= 1) {
            auto prev = dummyNode, curr = dummyNode->next;
            while (curr) {
                auto lNode = curr;
                for (int i = 1; i < subLen && curr->next; i++) curr = curr->next;

                auto rNode = curr->next;
                curr->next = nullptr;
                curr = rNode;
                for (int i = 1; i < subLen && curr && curr->next; i++) curr = curr->next;

                ListNode *next = nullptr;
                if (curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }

                prev->next = mergeListNode(lNode, rNode);
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
    static ListNode *mergeListNode(ListNode *lNode, ListNode *rNode) {
        auto dummyNode = new ListNode(0);
        auto cur = dummyNode;
        while (lNode && rNode) {
            if (lNode->val < rNode->val) {
                cur->next = lNode;
                lNode = lNode->next;
            } else {
                cur->next = rNode;
                rNode = rNode->next;
            }
            cur = cur->next;
        }

        if (!lNode) cur->next = rNode;
        else cur->next = lNode;

        cur = dummyNode->next;
        delete dummyNode;
        return cur;

    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> head = {4, 2, 1, 3};
    auto node = vecT2ListNode(head);
    vector<int> res = {1, 2, 3, 4};

    IC(head, res);

    auto result = solution->sortList(node);
    outListNode(result);

    deleteListNode(result);
//    IC();



    // code end

    return 0;
}


