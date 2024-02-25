

#include "../../combofish_utils.hpp"
#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;

// struct ListNode {
//     int val;
//     struct ListNode *next;

//     ListNode(int x) : val(x), next(nullptr) {}
// };

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode *mergeNode(ListNode *head) {
        // write code here

        auto dummyNode = new ListNode(0);
        dummyNode->next = head;

        auto curr = dummyNode;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val % 2 == 1) {
                auto oid_node = curr->next;
                outListNode(oid_node);

                auto oid_next = oid_node->next;
                while (oid_next != nullptr && oid_next->val % 2 == 0) {
                    oid_node->val += oid_next->val;
                    auto tmp = oid_next;
                    oid_next = oid_next->next;
                    delete tmp;
                }

                outListNode(oid_next);

                oid_node->next = oid_next;

                curr = oid_node;

            } else {
                curr = curr->next;
            }
        }

        curr = dummyNode->next;
        delete dummyNode;
        return curr;
    }
};
int main(int argc, char const *argv[]) {


    vector<int> nums = {2, 3, 4, 1, 2, 2, 3};
    vector<int> ans = {2, 7, 5, 3};

    IC(nums, ans);

    auto head = vecT2ListNode(nums);

    Solution sol;
    auto result = sol.mergeNode(head);

    outListNode(result);

    return 0;
}
