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
private:
    std::pair<int, int> robTree(TreeNode *cur) {
        if (!cur) return {0, 0};

        auto left = robTree(cur->left);
        auto right = robTree(cur->right);

        int rob_cur = cur->val + left.first + right.first;
        int rob_child = std::max(left.first, left.second) + std::max(right.first, right.second);
        return {rob_child, rob_cur};
    }

public:
    int rob(TreeNode *root) {
        auto cur = robTree(root);
        return std::max(cur.first, cur.second);
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    auto t1 = new TreeNode(1);
    auto t1_2 = new TreeNode(1);
    auto t3 = new TreeNode(3);
    auto t4 = new TreeNode(4);
    auto t5 = new TreeNode(5);
    auto t3_2 = new TreeNode(3);

    auto root = t3;
    root->left = t4;
    root->right = t5;

    t4->left = t1;
    t4->right = t3_2;

    t5->right = t1_2;

    int rel = 9;
    IC(solution->rob(root) == rel);


    deleteTreeNode(root);

    // code end

    delete solution;
    return 0;
}


