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

class Solution {

    // function start.
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        auto dummyNode = new ListNode();
        dummyNode->next = head;

        auto prev = dummyNode;
        auto ln = left - 1;
        while (ln-- > 0) {
            prev = prev->next;
        }

        auto curr = prev->next;
        ListNode *next;

        auto diff = right - left;
        while (diff-- > 0) {
            next = curr->next;
            IC(prev->val, curr->val, next->val);

            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        curr = dummyNode->next;
        delete dummyNode;
        return curr;


    }

private:


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> head = {1, 2, 3, 4, 5};
    auto head_list = vecT2ListNode(head);

    int left = 2, right = 4;

    IC(head, left, right);
    solution->reverseBetween(head_list, left, right);

    deleteListNode(head_list);
    // code end

    return 0;
}