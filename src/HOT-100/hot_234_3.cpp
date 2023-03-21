/**
-- question: 回文链表
-- method:
 - [ ] 将值复制到数组中后用双指针法
 - [ ] 递归
 - [*] 快慢指针  --- best ---
 - [ ] queue

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
        ListNode *firstHalfHead = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfHead->next);

        ListNode *node1 = head;
        ListNode *node2 = secondHalfStart;

        bool result = true;
        while (result && node2) {
            if (node1->val != node2->val) result = false;
            node1 = node1->next;
            node2 = node2->next;
        }

        firstHalfHead->next = reverseList(secondHalfStart);
        return result;
    }

private:

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode *endOfFirstHalf(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

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
    bool rel = true;

    IC(head, rel);
    auto headL = vecT2ListNode(head);
    IC(solution->isPalindrome(headL));

    deleteListNode(headL);
    // code end

    return 0;
}


