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

        auto lNode = dummyNode;
        auto ln = left-1;
        while (ln-- > 0) {
            lNode = lNode->next;
        }

        IC(lNode->val);

        auto rNode = lNode;
        auto diff = right - left + 1;
        IC(diff, right, left, right - left + 1);

        while (diff-- > 0) {
            rNode = rNode->next;
        }

        IC(rNode->val);

        auto last = rNode->next;
        rNode->next = nullptr;
        auto rv = revList(lNode->next);

        IC(rv);
        outListNode(rv);

        lNode->next->next = last;
        lNode->next = rv;


        lNode = dummyNode->next;
        delete dummyNode;
        return lNode;


    }

private:
    ListNode *revList(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            auto tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        return prev;
    }
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