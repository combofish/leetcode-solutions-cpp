/**
-- question:
-- method:
 - [*] 将值复制到数组中后用双指针法
 - [ ] 递归
 - [ ] 快慢指针

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
    bool isPalindrome(ListNode *head) {
        vector<int> ans;
        while (head) {
            ans.emplace_back(head->val);
            head = head->next;
        }

        int lk = 0, rk = ans.size() - 1;
        while (lk <= rk) {
            if (ans[lk] != ans[rk]) return false;
            lk++;
            rk--;
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
    auto node = vecT2ListNode(head);
    bool ans = true;

    IC(head, ans);
    IC(solution->isPalindrome(node));


    deleteListNode(node);
    // code end

    return 0;
}


