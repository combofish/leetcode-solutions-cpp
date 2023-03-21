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

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int over = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            int tmp = n1 + n2 + over;
            if (!head) {
                head = tail = new ListNode(tmp % 10);
            } else {
                tail->next = new ListNode(tmp % 10);
                tail = tail->next;
            }

            over = tmp / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (over) tail->next = new ListNode(over);
        return head;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> l1 = {2, 4, 3}, l2 = {5, 6, 4};
    vector<int> rel = {7, 0, 8};
    string res = "342 + 465 = 807";
    IC(l1, l2, rel, res);

    auto ln1 = vec_t2list_node(l1);
    auto ln2 = vec_t2list_node(l2);


    out_list_node(ln1, "ln1");
    out_list_node(ln2, "ln2");

    auto result = solution->addTwoNumbers(ln1, ln2);
    out_list_node(result);

    // vector<int> l1_2 = {9, 9, 9, 9, 9, 9, 9}, l2_2 = {9, 9, 9, 9}, rel_2 = {8, 9, 9, 9, 0, 0, 0, 1};
//    vector<int> l1_2 = {2,4,9}, l2_2 = {5,6,4,9}, rel_2 = {7,0,4,1};
//
//    IC(l1_2);
//    IC(l2_2);
//    IC(rel_2);
//    out_list_node(solution->addTwoNumbers(
//            vec_t2list_node(l1_2),
//            vec_t2list_node(l2_2)
//    ));

    deleteListNode(result);

    deleteListNode(ln1);
    deleteListNode(ln2);
    // code end

    delete solution;
    return 0;
}


