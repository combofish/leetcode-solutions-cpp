
/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    ListNode *reverseList(ListNode *head) {
        auto cur = head;
        ListNode *tmp;
        ListNode *pre = nullptr;

        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
	
        return pre;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t head = {1, 2, 3, 4, 5};
    auto input = vec_t2list_node(head);
    out_list_node(input);

    auto res = solution->reverseList(input);
    out_list_node(res);

    
    // deleteListNode(input);
    deleteListNode(res);

    // code end

    delete solution;
    return 0;
}
