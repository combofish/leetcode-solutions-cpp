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
     * Err: 已取 cur->next ，如果此值为空， 则没有和之前节点的指向性。
     * @param l1
     * @param l2
     * @return
     */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root = l1;
        int over = 0;
        while (l1 && l2) {
            int tmp = l1->val + l2->val + over;
            if (tmp > 9) {
                tmp -= 10;
                over = 1;
            } else {
                over = 0;
            }
            l1->val = tmp;
            l1 = l1->next;
            l2 = l2->next;
        }

        out_list_node(root);

        if (!l1 && l2) {
            l1 = l2;
            IC("2-1");
        }
        while (l1 != nullptr) {
            IC();
            int tmp = l1->val + over;
            if (tmp > 9) {
                tmp -= 10;
                over = 1;
            } else {
                over = 0;
            }
            l1->val = tmp;
            l1 = l1->next;
        }

        IC(over);
        if (over) {
            auto cur = root;
            while(cur->next){
                cur = cur->next;
            }
            cur->next = new ListNode(over);
        }

        return root;
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
//    IC(l1, l2, rel, res);

    auto ln1 = vec_t2list_node(l1);
    auto ln2 = vec_t2list_node(l2);

//    out_list_node(ln1, "ln1");
//    out_list_node(ln2, "ln2");

//    auto result = solution->addTwoNumbers(ln1, ln2);
//    out_list_node(result);

    // vector<int> l1_2 = {9, 9, 9, 9, 9, 9, 9}, l2_2 = {9, 9, 9, 9}, rel_2 = {8, 9, 9, 9, 0, 0, 0, 1};
    vector<int> l1_2 = {2,4,9}, l2_2 = {5,6,4,9}, rel_2 = {7,0,4,1};

    IC(l1_2);
    IC(l2_2);
    IC(rel_2);
    out_list_node(solution->addTwoNumbers(
            vec_t2list_node(l1_2),
            vec_t2list_node(l2_2)
    ));


    // code end

    delete solution;
    return 0;
}


