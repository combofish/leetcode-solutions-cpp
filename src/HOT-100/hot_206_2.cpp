/**
-- question:
-- method:
 - [] iteration
 - [*] recursive

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
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> head = {1, 2, 3, 4, 5};
    vector<int> rel = {5, 4, 3, 2, 1};
    IC(head, rel);

    auto head_list = vecT2ListNode(head);

    auto out_list = solution->reverseList(head_list);

    outListNode(out_list);

    deleteListNode(out_list);

    // code end

    return 0;
}
