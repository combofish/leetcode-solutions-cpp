/**
-- question:
-- method:
 - [ ] vector
 - [*] iterate
 - [ ] recursive


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
    ListNode *reverseList(ListNode *head) {
        ListNode* prev= nullptr;
        auto curr = head;
        while(curr){
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> head = {1, 2, 3, 4, 5};
    vector<int> ans = {5, 4, 3, 2, 1};

    IC(head, ans);
    auto node = vecT2ListNode(head);
    auto resNode = solution->reverseList(node);

    outListNode(resNode);
    deleteListNode(resNode);
    // deleteListNode(node);
    // code end

    return 0;
}


