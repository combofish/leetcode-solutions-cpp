/**
-- question: 相交链表
-- method:
 - [*] 哈希集合

--result:

-- analyse:
Time: O( m+n )
Space: O( m )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> cache;
        ListNode *cur = headA;
        while (cur) {
            cache.insert(cur);
            cur = cur->next;
        }

        ListNode *node = headB;
        while (node) {
            if (cache.count(node)) return node;
            node = node->next;
        }

        return nullptr;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int intersectVal = 8;
    vector<int> listA = {4, 1};
    vector<int> listB = {5, 6, 1};
    vector<int> listC = {8, 4, 5};
    int skipA = 2, skipB = 3;

    IC(intersectVal, listA, listB, skipA, skipB);

    auto lA = vecT2ListNode(listA);
    auto lB = vecT2ListNode(listB);
    auto lC = vecT2ListNode(listC);

    lA->next->next = lC;
    lB->next->next->next = lC;

    auto result = solution->getIntersectionNode(lA, lB);
    IC(result->val);
    outListNode(result);

    deleteListNode(lA);
    deleteListNode(lB, 3);

    // code end

    return 0;
}


