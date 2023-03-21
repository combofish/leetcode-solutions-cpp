/**
-- question: 合并两个排序的链表
-- method:
 - [ ] recursive
 - [*] iterate

--result:

-- analyse:
Time: O(n+m)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto dummyNode = new ListNode(0);
        auto head = dummyNode;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;

            // outListNode(dummyNode);
        }

        if (!l1) head->next = l2;
        else
            head->next = l1;

        head = dummyNode->next;
        delete dummyNode;
        return head;
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
