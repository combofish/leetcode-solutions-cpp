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

    // function start.
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next= head;

        ListNode *cur = dummyNode;
        ListNode *fast = dummyNode;

        while (n-- && fast) {
            fast = fast->next;
        }

        while (fast->next) {
            cur = cur->next;
            fast = fast->next;
        }

        IC(fast->val, cur->val);
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;

        cur = dummyNode->next;
        delete dummyNode;
        return cur;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> head = {1, 2, 3, 4, 5};
    int n = 2;
    vector<int> rel = {1, 2, 3, 5};
    IC(head, n, rel);

    auto root = vec_t2list_node(head);
    auto result = solution->removeNthFromEnd(root, n);

    out_list_node(result);
    deleteListNode(result);


    // code end

    delete solution;
    return 0;
}


