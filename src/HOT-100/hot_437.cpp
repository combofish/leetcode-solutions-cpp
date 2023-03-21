/**
-- question: 路径总和 III
-- method:
 - [*] 深度优先搜索
 - [ ]
 
--result:

-- analyse:
Time: O(N^2)
Space: O(N)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;

        traversal(root, targetSum);
        pathSum(root->right, targetSum);
        pathSum(root->left, targetSum);

        return result;
    }

private:
    int result = 0;
    void traversal(TreeNode *root, long targetSum) {
        if (!root) return;
        if (root->val == targetSum) ++result;
        traversal(root->left, targetSum - root->val);
        traversal(root->right, targetSum - root->val);
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto ll4 = new TreeNode(4);
    auto ll2 = new TreeNode(2, new TreeNode(7), ll4);
    auto ll5 = new TreeNode(5, new TreeNode(6), ll2);
    auto ll1 = new TreeNode(1, new TreeNode(0), new TreeNode(8));
    auto ll3 = new TreeNode(3, ll5, ll1);

    auto root = ll3;
    int targetSum = 8;
    int rel = 2;


    int result = solution->pathSum(root, targetSum);

    IC(rel);
    IC(result);
    IC(treenode_tools::levelOrder(root));
    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
