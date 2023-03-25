/**
-- question: 环形链表 II
-- method:
 - [ ] 哈希表
 - [*] 快慢指针

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
        auto fast = head, slow = head;

        while (fast) {
            slow = slow->next;
            if (!fast->next) return nullptr;
            fast = fast->next->next;

            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
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


