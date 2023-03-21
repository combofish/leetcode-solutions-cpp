/**
-- method:

--result:

-- analyse:
Time: O(n+m)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *head = dummyNode;

        while (list1 || list2) {
            if (list1 && list2) {
                if (list1->val < list2->val) {
                    head->next = list1;
                    head = head->next;
                    list1 = list1->next;
                } else {
                    head->next = list2;
                    head = head->next;
                    list2 = list2->next;
                }
            } else if (list1) {
                head->next = list1;
                list1 = list1->next;
                head = head->next;
            } else {
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
        }

        head = dummyNode->next;
        delete dummyNode;
        return head;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> l1 = {1, 2, 4}, l2 = {1, 3, 4};
    vector<int> rel = {1, 1, 2, 3, 4, 4};
    IC(l1, l2, rel);

    auto ll1 = vecT2ListNode(l1);
    auto ll2 = vecT2ListNode(l2);

    auto ll3 = solution->mergeTwoLists(ll1, ll2);

    outListNode(ll3);

    deleteListNode(ll3);

    // code end

    delete solution;
    return 0;
}


