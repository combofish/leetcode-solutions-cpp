/**
-- question: 从前序与中序遍历序列构造二叉树
-- method:
 - [ ] 递归
 - [-] 迭代

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
        if (preorder.empty()) return nullptr;
        int n = preorder.size();

        auto root = new TreeNode(preorder.front());
        stack<TreeNode *> st;
        st.push(root);

        int inIdx = 0;
        for (int i = 1; i < n; i++) {
            int preorder_val = preorder[i];
            auto node = st.top();
            if (node->val != inorder[inIdx]) {
                node->left = new TreeNode(preorder_val);
                st.push(node->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[inIdx]) {
                    node = st.top();
                    st.pop();
                    ++inIdx;
                }
                IC(preorder_val);
                node->right = new TreeNode(preorder_val);
                st.push(node->right);
            }

        }
        return root;
    }

private:
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
