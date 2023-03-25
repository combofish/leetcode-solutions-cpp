/**
-- question:
-- method:
 - [ ] 将值复制到数组中后用双指针法
 - [*] 递归
 - [ ] 快慢指针

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
        frontNode = head;
        return recursiveCheck(head);

    }

private:

    ListNode *frontNode;

    bool recursiveCheck(ListNode *node) {
        if (node) {
            IC(node->val);
            if (!recursiveCheck(node->next)) return false;
            if (node->val != frontNode->val) return false;
            frontNode = frontNode->next;
        }

        return true;
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


