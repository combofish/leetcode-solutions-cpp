/**
-- question: 反转链表
-- method:
 - [*] 递归
 - [ ] 迭代

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
    ListNode *reverseList(ListNode *head) {
        while (!head || !head->next) return head;

        auto node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
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
