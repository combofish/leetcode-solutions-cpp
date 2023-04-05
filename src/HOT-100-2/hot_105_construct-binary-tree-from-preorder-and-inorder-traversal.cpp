/**
-- question: 从前序与中序遍历序列构造二叉树
-- method:
 - [-] 递归
 - [ ] 迭代

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"

/**
对于一棵树：前序遍历的形式
 [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
 中序遍历的形式是：
 [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
 */


class Solution {

    // function start.
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++)
            idx[inorder[i]] = i;

        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    unordered_map<int, int> idx;

    TreeNode *build(const vector<int> &preorder, const vector<int> &inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        auto root_val = preorder[pl];
        auto in_root_idx = idx[root_val];

        auto root = new TreeNode(root_val);
        int size_left = in_root_idx - il;

        root->left = build(preorder, inorder, pl + 1, pl + size_left, il, il + size_left - 1);
        root->right = build(preorder, inorder, pl + 1 + size_left, pr, in_root_idx + 1, ir);
        return root;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};

    string ans = "[3,9,20,null,null,15,7]";

    IC(preorder, inorder, ans);

    auto node = solution->buildTree(preorder, inorder);
    IC(treenode_tools::levelOrder(node));

    treenode_tools::deleteTreeNode(node);

    // code end

    return 0;
}
