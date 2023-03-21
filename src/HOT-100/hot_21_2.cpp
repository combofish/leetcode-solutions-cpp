/**
-- method:

--result:

-- analyse:
Time: O(n+m)
Space: O(m+n)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list2) return list1;
        else if (!list1) return list2;
        else if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
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


