/**
-- question: 环形链表 II
-- method:
 - [*] 哈希表
 - [ ] 快慢指针

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *detectCycle(ListNode *head) {
        auto cache = unordered_set<ListNode *>();

        while (head) {
            if (cache.count(head)) return head;

            cache.insert(head);
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
