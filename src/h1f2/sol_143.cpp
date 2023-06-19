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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        auto head1 = head;
        auto head2 = head->next;

        auto node1 = head1;
        auto node2 = head2;
        auto cur = head2->next;
        int cnt = 1;

        while (cur) {
            if (cnt % 2) {
                node1->next = cur;
                node1 = node1->next;
            } else {
                node2->next = cur;
                node2 = node2->next;
            }
            cur = cur->next;
            ++cnt;
        }
        node1->next = nullptr;
        node2->next = nullptr;

        auto rev = revList(head2);
        outListNode(head1, "head1");
        outListNode(rev, "rev");

        while (head) {
            auto next = head->next;
            head->next = rev;
            auto tmp = rev->next;
            head->next->next = next;
            rev = tmp;
            head = next;
        }

    }

private:
    ListNode *revList(ListNode *node) {
        ListNode *prev = nullptr;
        auto curr = node;
        while (curr) {
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3, 4};
    auto node = vecT2ListNode(nums);
    outListNode(node);

    solution->reorderList(node);
    outListNode(node);

    deleteListNode(node);
    // code end

    return 0;
}