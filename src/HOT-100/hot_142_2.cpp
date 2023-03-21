/**
-- question: 环形链表 II
-- method:
 - [ ] 哈希表
 - [*] 快慢指针

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *detectCycle(ListNode *head) {

        auto slow = head, fast = head;
        while (fast) {
            slow = slow->next;
            if (!fast->next) return nullptr;

            fast = fast->next->next;
            if (fast == slow) {
                auto ptr = head;
                while (ptr != slow) {
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
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
    auto l2 = new ListNode(2);
    auto l0 = new ListNode(0);
    auto l4 = new ListNode(-4);
    auto root = new ListNode(3);

    root->next = l2;
    l2->next = l0;
    l0->next = l4;
    l4->next = l2;

    vector<int> nums = {3, 2, 0, -4};
    int pos = 1;
    IC(nums, pos);

    auto res = solution->detectCycle(root);
    IC(res->val);

    deleteListNode(root, 4);

    // code end

    return 0;
}
