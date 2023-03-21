/**
-- question: 重建二叉树
-- method:
 - [*] 递归

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) cache[inorder[i]] = i;
        return traversal(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    unordered_map<int, int> cache;
    TreeNode *traversal(const vector<int> &preorder, const vector<int> &inorder, int ls, int le, int is, int ie) {
        if (ls > le) return nullptr;

        int rootVal = preorder[ls];
        int rootInorderIdx = cache[rootVal];
        int subSize = rootInorderIdx - is;
        auto root = new TreeNode(rootVal);
        root->left = traversal(preorder, inorder, ls + 1, ls + subSize, is, rootInorderIdx - 1);
        root->right = traversal(preorder, inorder, ls + subSize + 1, le, rootInorderIdx + 1, ie);
        return root;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto l20 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    auto l3 = new TreeNode(3, new TreeNode(9), l20);
    auto root = l3;

    IC(treenode_tools::levelOrder(root));
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    IC(preorder, inorder);
    auto result = solution->buildTree(preorder, inorder);

    IC(treenode_tools::levelOrder(result));
    treenode_tools::deleteTreeNode(result);
    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
