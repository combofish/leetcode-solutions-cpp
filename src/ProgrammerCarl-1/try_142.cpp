/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                ListNode *idx1 = fast;
                ListNode *idx2 = head;
                while (idx1 != idx2) {
                    idx1 = idx1->next;
                    idx2 = idx2->next;
                }

                return idx2;
            }
        }

        return nullptr;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    ListNode *input_2 = new ListNode(2);

    input_2->next = new ListNode(0, new ListNode(-4, input_2));

    ListNode *input = new ListNode(3, input_2);
    IC(input != nullptr);

    deleteListNode(input, 4);

    // code end

    delete solution;
    return 0;
}
