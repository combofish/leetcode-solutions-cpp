/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int pathSum(TreeNode *root, int targetSum) {
        ump[0] = 1;
        return backtracking(root, 0, targetSum);
    }

private:
    unordered_map<long long, int> ump;

    int backtracking(TreeNode *node, long long cur, int targetSum) {

        if (!node) return 0;
        cur += node->val;

        int ans = 0;
        if (ump.count(cur - targetSum)) ans += ump[cur - targetSum];

        ump[cur]++;
        ans += backtracking(node->left, cur, targetSum);
        ans += backtracking(node->right, cur, targetSum);

        ump[cur]--;

        IC(ump, ans);

        return ans;
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

//    auto node3 = new TreeNode(3, new TreeNode(3), new TreeNode(-2));
//    auto node2 = new TreeNode(2, nullptr, new TreeNode(1));
//    auto node5  = new TreeNode(5, node3, node2);
//    auto node_3 = new TreeNode(-3, nullptr, new TreeNode(11));
//    auto root = new TreeNode(10, node5, node_3);
//    int ans = 3;
// int targetSum = 8;

//    auto root = new TreeNode(1,
//                             new TreeNode(2,
//                                          new TreeNode(3,
//                                                       new TreeNode(4,
//                                                                    new TreeNode(5),
//                                                                    nullptr
//                                                       ),
//                                                       nullptr),
//                                          nullptr),
//                             nullptr);
//
//
//    int ans = 2;
//    int targetSum = 3;

    auto root = new TreeNode(1,
                             new TreeNode(-2,
                                          new TreeNode(1,
                                                       new TreeNode(-1),
                                                       nullptr),
                                          new TreeNode(3)),
                             new TreeNode(-3,
                                          new TreeNode(-2),
                                          nullptr));

    int targetSum = -1;
    int ans = 4;

    IC(treenode_tools::levelOrder(root));
    IC(targetSum, ans);

    IC(solution->pathSum(root, targetSum));

    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}


