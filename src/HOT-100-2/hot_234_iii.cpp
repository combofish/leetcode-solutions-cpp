/**
-- question:
-- method:
 - [ ] 将值复制到数组中后用双指针法
 - [ ] 递归
 - [*] 快慢指针

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool isPalindrome(ListNode *head) {
        if (!head) return true;

        auto firstHalf = endOfHalf(head);
        auto secondReverseHalf = reverseList(firstHalf->next);

        auto lNode = head;
        auto rNode = secondReverseHalf;
        bool ans = true;

        while(ans && rNode){
            if(lNode->val != rNode->val) ans = false;

            lNode= lNode->next;
            rNode = rNode->next;
        }

        firstHalf->next = reverseList(secondReverseHalf);
        return ans;
    }

private:
    ListNode *reverseList(ListNode *node) {
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

    ListNode *endOfHalf(ListNode *head) {
        auto fast = head;
        auto slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> head = {1, 2, 2, 1};
    auto node = vecT2ListNode(head);
    bool ans = true;

    IC(head, ans);
    IC(solution->isPalindrome(node));


    deleteListNode(node);
    // code end

    return 0;
}


