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
        ans = 0;
        vector<int> path;
        uet.clear();

        uet.insert(root);
        backtracking(root, (long long) targetSum, 0, path);
        return ans;
    }

private:
    int ans = 0;
    unordered_set<TreeNode *> uet;

    void backtracking(TreeNode *node, const long long &targetSum, long long sum, vector<int> &path) {
        auto tmp = sum + node->val;
        path.push_back(node->val);
        IC(path, tmp, node->val);

        if (targetSum == tmp) {
            ans++;
            IC(ans);
        }
        if (node->left) backtracking(node->left, targetSum, tmp, path);
        if (node->right) backtracking(node->right, targetSum, tmp, path);


        vector<int> new_path;
        if (node->left && !uet.count(node->left)) {
            uet.insert(node->left);
            backtracking(node->left, targetSum, 0, new_path);
        }
        if (node->right && !uet.count(node->right)) {
            uet.insert(node->right);
            backtracking(node->right, targetSum, 0, new_path);
        }

        path.pop_back();
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


