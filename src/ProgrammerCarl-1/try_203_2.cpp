/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

struct MyListNode {
    int val;
    MyListNode *next;
    MyListNode() : val(0), next(nullptr){};
    MyListNode(int x) : val(x), next(nullptr){};
    MyListNode(int x, MyListNode *next) : val(x), next(next){};
};

class Solution {
public:
    // function start.
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *cur = dummyNode;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }

        head = dummyNode->next;
        delete dummyNode;
        return head;
    }

    // function end.
};

int main() {
    auto solution = new Solution();
    //Solution a;


    // code start
    vec_t head = {1, 2, 6, 3, 4, 5};
    int val = 6;

    //ListNode *l_head = vec_t2list_node(head);

    ListNode *l_head = new ListNode(9, new ListNode(6, new ListNode(6, new ListNode(6))));
    out_list_node(l_head);


    ListNode *res = solution->removeElements(l_head, val);
    //ListNode *res = a.removeElements(l_head, val);


    out_list_node(res);


    while (res != nullptr && res->next != nullptr) {
        ListNode *tmp = res;
        res = res->next;
        delete tmp;
    }

    if (res != nullptr) delete res;

    // delete [] res;

    // delete l_head;
    // delete res

    // code end

    delete solution;
    return 0;
}
