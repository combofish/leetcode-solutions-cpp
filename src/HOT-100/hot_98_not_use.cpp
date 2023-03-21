/**
-- question:
-- method:
 - []

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
    // 范围限制， 这个方法不好

    bool isValidBST(TreeNode *root) {
        return traversal(root, INT_MIN, INT_MAX);
    }

private:


    bool traversal(TreeNode *node, int l, int r) {
        if (!node) return true;

        if (node->val <= l || node->val >= r) return false;

        bool left_result = traversal(node->left, l, node->val);
        bool right_result = traversal(node->right, node->val, r);

        return left_result && right_result;
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto root = new TreeNode(5, new TreeNode(1), nullptr);
    auto t4 = new TreeNode(4, new TreeNode(3), new TreeNode(6));
    root->right = t4;

    bool rel = false;
    IC(solution->isValidBST(root) == rel);

    deleteTreeNode(root);


    IC(INT_MIN, INT_MAX);

    long iMin = -std::pow(2, 31);
    long iMax = std::pow(2, 31) - 1;
    IC(iMin, iMax);


    // code end

    return 0;
}


