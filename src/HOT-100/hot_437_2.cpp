/**
-- question: 路径总和 III
-- method:
 - [ ] 深度优先搜索
 - [*] 前缀和
 
--result:

-- analyse:
Time: O(N)
Space: O(N)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <math.h>

class Solution {

    // function start.
public:
    int pathSum(TreeNode *root, int targetSum) {
        prefix[0] = 1;
        return backtracking(root, 0, targetSum);
    }

private:
    unordered_map<long long, int> prefix;
    int backtracking(TreeNode *node, long long curr, int &targetSum) {
        if (!node) return 0;
        int ret = 0;
        curr += node->val;
        if (prefix.count(curr - targetSum)) ret = prefix[curr - targetSum];

        prefix[curr]++;
        ret += backtracking(node->left, curr, targetSum);

        IC(prefix);
        ret += backtracking(node->right, curr, targetSum);
        prefix[curr]--;
        return ret;
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
