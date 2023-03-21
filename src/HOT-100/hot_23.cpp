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

    // function start.
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists.front();

        ListNode *root = lists.front();
        for (int i = 1; i < lists.size(); i++) {
            root = mergeTwoLists(root, lists[i]);
            outListNode(root);
        }

        return root;
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *head = dummyNode;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        if (l1) head->next = l1;
        if (l2) head->next = l2;

        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<vector<int>> lists = {{1, 4, 5},
                                 {1, 3, 4},
                                 {2, 6}};
    vector<int> rel = {1, 1, 2, 3, 4, 4, 5, 6};
    IC(lists, rel);

    vector<ListNode *> inputs;
    for (const auto &item: lists)
        inputs.push_back(vecT2ListNode(item));

    auto result = solution->mergeKLists(inputs);
    outListNode(result);

    deleteListNode(result);
    // code end

    delete solution;
    return 0;
}


