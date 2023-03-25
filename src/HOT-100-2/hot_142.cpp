/**
-- question: 环形链表 II
-- method:
 - []

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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        unordered_set<ListNode *> uet;

        while (head) {
            if (uet.count(head)) return head;

            uet.insert(head);
            head = head->next;
        }

        return nullptr;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto n3 = new ListNode(3);
    auto n2 = new ListNode(2);
    auto n0 = new ListNode(0);
    auto n_4 = new ListNode(-4);

    n3->next = n2;
    n2->next = n0;
    n0->next = n_4;
    n_4->next = n2;

    int res = 2;
    IC(res);
    auto ans = solution->detectCycle(n3);
    IC(ans->val);

    deleteListNode(n3, 4);

    // code end

    return 0;
}


