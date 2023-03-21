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
        for (auto node: lists)
            if (node) q.push({node->val, node});

        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }

        return head.next;
    }

private:

    struct Status {
        int val;
        ListNode *ptr;

        bool operator<(const Status &rhs) const {
            return val > rhs.val;
        }
    };

    std::priority_queue<Status> q;


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



//    vector<int> tes = {3, 4, 5, 2, 5, 2, 65, 2, 1, 2, 3, 3, 4, 56, 2, 2, 3, 4, 6,8};
//    std::priority_queue<int> que;
//    for (const auto &item: tes)
//        que.push(item);
//
//    while (!que.empty()) {
//        IC(que.top());
//        que.pop();
//    }
    delete solution;
    return 0;
}


