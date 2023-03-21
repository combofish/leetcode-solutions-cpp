/**
-- question: 合并两个排序的链表
-- method:
 - [*] recursive
 - [ ] iterate

--result:

-- analyse:
Time: O(n+m)
Space: O(n+m)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        else if (!l2)
            return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums1 = {1, 2, 4}, nums2 = {1, 3, 4};
    vector<int> rel = {1, 1, 2, 3, 4, 4};

    IC(nums1, nums2, rel);

    auto result = solution->mergeTwoLists(vecT2ListNode(nums1), vecT2ListNode(nums2));

    outListNode(result);
    deleteListNode(result);
    // code end

    return 0;
}
