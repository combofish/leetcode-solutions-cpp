/**
-- question:
-- method:
 - [-] vector
 - [*] iterate
 - [ ] recursive

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
    ListNode *reverseList(ListNode *head) {
        vector<int> rec;
        while (head) {
            rec.emplace_back(head->val);
            head = head->next;
        }

        IC(rec);

        auto dummyNode = new ListNode(0);
        auto node = dummyNode;
        for(int i = rec.size()-1; i>=0;i--){
            node->next = new ListNode(rec[i]);
            node = node->next;
        }


        node = dummyNode->next;
        delete dummyNode;
        return node;
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
    deleteListNode(node);
    // code end

    return 0;
}


