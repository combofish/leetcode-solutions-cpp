/**
-- question: 从尾到头打印链表
-- method:
 - [ ] record, reverse
 - [ ] stack
 - [*] recursive

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
    vector<int> reversePrint(ListNode *head) {
        if (!head) return vector<int>();

        vector<int> result;
        traversal(head, result);
        return result;
    }


private:
    void traversal(ListNode *node, vector<int> &rec) {
        if (node->next) traversal(node->next, rec);
        rec.emplace_back(node->val);
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> head = {1, 3, 2}, rel = {2, 3, 1};
    IC(head, rel);

    auto root = vecT2ListNode(head);
    IC(solution->reversePrint(root));

    deleteListNode(root);
    // code end

    return 0;
}
