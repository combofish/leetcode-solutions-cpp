/**
-- question: 回文链表
-- method:
 - [ ] 将值复制到数组中后用双指针法
 - [ ] 递归
 - [ ] 快慢指针  --- best ---
 - [*] queue

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool isPalindrome(ListNode *head) {
        std::deque<int> qu;
        while (head) {
            qu.push_back(head->val);
            head = head->next;
        }

        while (qu.size() > 1) {
            if (qu.front() != qu.back()) return false;
            qu.pop_back();
            qu.pop_front();
        }
        return true;

    }

private:

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


