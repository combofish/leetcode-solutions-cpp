/**
-- question: 环形链表
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
    bool hasCycle(ListNode *head) {
        auto cache = unordered_set<ListNode *>();
        auto node = head;
        while (node) {
            if (cache.count(node)) return true;
            cache.insert(node);
            node = node->next;
        }

        return false;
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
