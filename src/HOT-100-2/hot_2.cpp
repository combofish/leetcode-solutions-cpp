/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int over = 0;
        auto dummyNode = new ListNode(0);
        auto head = dummyNode;

        while (l1 || l2 || over) {

            auto n1 = l1 == nullptr ? 0 : l1->val;
            auto n2 = l2 == nullptr ? 0 : l2->val;

            int up = n1 + n2 + over;
            if (up > 9) {
                over = 1;
                up -= 10;
            } else {
                over = 0;
            }
            head->next = new ListNode(up);
            head = head->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            outListNode(dummyNode);
        }

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
    vector<int> l1 = {9, 9, 9, 9, 9, 9, 9}, l2 = {9, 9, 9, 9}, result = {8, 9, 9, 9, 0, 0, 0, 1};

    IC(l1, l2, result);
    auto ll1 = vecT2ListNode(l1);
    auto ll2 = vecT2ListNode(l2);

    auto res_l = solution->addTwoNumbers(ll1, ll2);

    outListNode(res_l);

    deleteListNode(ll1);
    deleteListNode(ll2);
    deleteListNode(res_l);
    // code end

    return 0;
}
