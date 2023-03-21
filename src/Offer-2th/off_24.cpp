/**
-- question: 反转链表
-- method:
 - [ ] 递归
 - [*] 迭代

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
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        auto curr = head;
        while (curr) {
            auto node = curr->next;
            curr->next = pre;
            pre = curr;
            curr = node;
        }
        return pre;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto node = vecT2ListNode(nums);

    outListNode(node);
    auto revNode = solution->reverseList(node);
    outListNode(revNode);
    deleteListNode(revNode);
    // code end

    return 0;
}
