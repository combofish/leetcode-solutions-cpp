/**
-- question: 环形链表
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        auto fast = head->next;
        auto slow = head;

        while (slow != fast) {
            if (!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
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
    bool rel = true;
    IC(nums, rel);

    auto res = solution->hasCycle(root);
    IC(res == rel);

    deleteListNode(root, 4);

    // code end

    return 0;
}
