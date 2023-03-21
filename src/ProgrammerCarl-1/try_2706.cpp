/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <tuple>

class Solution {
public:
    // function start.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1 = headA;
        ListNode *tmp2 = headB;

        int len1 = 0;
        int len2 = 0;
        while (tmp1 != nullptr) {
            ++len1;
            tmp1 = tmp1->next;
        }

        while (tmp2 != nullptr) {
            ++len2;
            tmp2 = tmp2->next;
        }

        IC(len1, len2);

        tmp1 = headA;
        tmp2 = headB;

        if (len2 > len1) {
            std::swap(len1, len2);
            std::swap(tmp1, tmp2);
        }

        int gap = len1 - len2;
        while (gap--) {
            tmp1 = tmp1->next;
        }

        while (tmp1 != nullptr) {
            if (tmp1 == tmp2) {
                return tmp1;
            }

            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        return nullptr;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    vec_t common = {2, 0, 3};
    auto commonNode = vec_t2list_node(common);

    auto listNode1 = new ListNode(9, new ListNode(7, commonNode));
    auto listNode2 = new ListNode(8, commonNode);

    out_list_node(listNode1);
    out_list_node(listNode2);

    ListNode *res = solution->getIntersectionNode(listNode1, listNode2);
    out_list_node(res);

    deleteListNode(listNode1);
    delete listNode2;

    // code start

    // code end

    delete solution;
    return 0;
}
