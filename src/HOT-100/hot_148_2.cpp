/**
-- question: 排序链表
-- method:
 - [ ] sort, create
 - [*] 自顶向下归并排序
 - [ ] 自底向上归并排序

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( log(n) )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    ListNode *sortList(ListNode *head) {
        return sortList(head, nullptr);
    }

private:
    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (!head) return nullptr;

        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            fast = fast->next;
            slow = slow->next;
            if (fast != tail) fast = fast->next;
        }

        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *node1, ListNode *node2) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *temp = dummyNode;
        ListNode *cur1 = node1, *cur2 = node2;

        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                temp->next = cur1;
                cur1 = cur1->next;
            } else {
                temp->next = cur2;
                cur2 = cur2->next;
            }
            temp = temp->next;
        }

        if (cur1) {
            temp->next = cur1;
        } else {
            temp->next = cur2;
        }
        temp = dummyNode->next;
        delete dummyNode;
        return temp;
    }
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

    // deleteListNode(headL);

    deleteListNode(result);
    // code end

    return 0;
}
