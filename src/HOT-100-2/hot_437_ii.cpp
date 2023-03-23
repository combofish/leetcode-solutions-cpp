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

        if (!root) return 0;

        auto ans = rootSum(root, (long long) targetSum);

        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);


        return ans;
    }

private:

    int rootSum(TreeNode *root, long long targetSum) {
        if(!root) return 0;

        int ret = 0;
        if(root->val == targetSum) ++ret;

        ret += rootSum(root->left, targetSum- root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;

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


