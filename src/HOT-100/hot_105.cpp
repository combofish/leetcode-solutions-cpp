/**
-- question: 从前序与中序遍历序列构造二叉树
-- method:
 - [*] 递归
 - [ ] 迭代

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) index[inorder[i]] = i;
        return traversal(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    unordered_map<int, int> index;
    TreeNode *traversal(const vector<int> &preOrder, const vector<int> &inO, int preL, int preR, int inL, int inR) {
        if (preL > preR) return nullptr;

        int preOrderrderRoot = preL;
        int inOrderRoot = index[preOrder[preOrderrderRoot]];

        auto root = new TreeNode(preOrder[preOrderrderRoot]);
        int sizeLeftSubtree = inOrderRoot - inL;

        root->left = traversal(preOrder, inO, preL + 1, preL + sizeLeftSubtree, inL, inOrderRoot - 1);
        root->right = traversal(preOrder, inO, preL + sizeLeftSubtree + 1, preR, inOrderRoot + 1, inR);
        return root;
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    auto rel = "[3,9,20,null,null,15,7]";

    IC(preorder, inorder, rel);
    auto result = solution->buildTree(preorder, inorder);

    IC(treenode_tools::levelOrder(result));
    treenode_tools::deleteTreeNode(result);

    // code end

    return 0;
}
