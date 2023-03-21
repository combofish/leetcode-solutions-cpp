/**
-- method:

--result:

-- analyse:
Time: O(n)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    ListNode *swapPairs(ListNode *head) {
        auto dummyNode = new ListNode(0);
        dummyNode->next = head;

        auto cur = dummyNode;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *l1 = cur->next;
            ListNode *l2 = cur->next->next->next;

            cur->next = l1->next;
            cur->next->next = l1;
            cur->next->next->next = l2;

            cur = cur->next->next;
        }

        cur = dummyNode->next;
        delete dummyNode;
        return cur;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start

    vec_t head = {1, 2, 3, 4};
    auto input = vec_t2list_node(head);
    auto res = solution->swapPairs(input);

    out_list_node(input);
    out_list_node(res);

    deleteListNode(res);

    // code end

    delete solution;
    return 0;
}
