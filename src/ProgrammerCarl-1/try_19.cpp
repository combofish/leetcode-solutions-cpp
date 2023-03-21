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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        ListNode *low = dummyNode;

        while (n-- && cur != nullptr) {
            cur = cur->next;
        }
//        cur = cur->next;

        while (cur->next) {
            cur = cur->next;
            low = low->next;
        }

        IC(cur->val, low->val);
        ListNode *tmp = low->next;
        low->next = tmp->next;
        delete tmp;


        cur = dummyNode->next;
        delete dummyNode;
        return cur;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t head = {1, 2, 3, 4, 5};
    int n = 2;

    auto input = vec_t2list_node(head);
    out_list_node(input);
    IC(n);

    auto res = solution->removeNthFromEnd(input, n);
    out_list_node(res);

    deleteListNode(res);

    // code end

    delete solution;
    return 0;
}
