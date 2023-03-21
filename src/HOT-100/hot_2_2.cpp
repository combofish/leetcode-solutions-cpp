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
    /**
     * recursive
     * @param cur
     * @param l1
     * @param l2
     * @param over
     */
    void backtracking(ListNode *cur, ListNode *l1, ListNode *l2, int over) {
        if (!l1 && !l2) {
            if (over) cur->next = new ListNode(over);
            return;
        }
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int tmp = n1 + n2 + over;

        cur->next = new ListNode(tmp % 10);
        cur = cur->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        backtracking(cur, l1, l2, tmp / 10);
        out_list_node(cur);
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root = new ListNode(0);
        backtracking(root, l1, l2, 0);
        ListNode* tmp = root->next;
        delete root;
        return tmp;
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


