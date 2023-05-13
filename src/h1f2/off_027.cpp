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

private:

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        auto curr = head;
        while (curr != nullptr) {
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;
        auto slow = head;
        auto fast = head;

        while (fast) {
            fast = fast->next;
            slow = slow->next;
            if (fast) fast = fast->next;
        }

        auto firstHalf = slow;
        ListNode *revList = reverseList(slow->next);

        auto n1 = head;
        auto n2 = revList;
        bool ans = true;

        while (ans && n2) {
            if (n1->val != n2->val) ans = false; // return false;
            n1 = n1->next;
            n2 = n2->next;
        }

        firstHalf->next = reverseList(revList);
        return ans;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> list = {1, 2, 3, 3, 2, 1};
    auto node = vecT2ListNode(list);

    bool ans = true;
    IC(list, ans);
    IC(solution->isPalindrome(node));

    deleteListNode(node);
    // code end

    return 0;
}