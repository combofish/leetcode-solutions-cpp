/**
-- question: 排序链表
-- method:
 - [*] sort, create
 - [ ] 自顶向下归并排序
 - [ ] 自底向上归并排序

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
    ListNode *sortList(ListNode *head) {
        ListNode *cur = head;
        vector<int> record;
        while (cur) {
            record.emplace_back(cur->val);
            cur = cur->next;
        }
        std::sort(record.begin(), record.end());
        IC(record);

        ListNode *dummyNode = new ListNode(0);
        cur = dummyNode;
        int i = 0;
        while (i < record.size()) {
            cur->next = new ListNode(record[i++]);
            cur = cur->next;
        }

        cur = dummyNode->next;
        delete dummyNode;
        return cur;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> head = {4, 2, 1, 3};
    vector<int> rel = {1, 2, 3, 4};

    IC(head, rel);

    auto headL = vecT2ListNode(head);
    auto result = solution->sortList(headL);

    outListNode(result);

    deleteListNode(headL);

    deleteListNode(result);
    // code end

    return 0;
}
