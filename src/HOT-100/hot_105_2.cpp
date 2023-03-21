/**
-- question: 从前序与中序遍历序列构造二叉树
-- method:
 - [ ] 递归
 - [*] 迭代

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
        if (!preorder.size()) return nullptr;

        auto root = new TreeNode(preorder.front());
        auto st = stack<TreeNode *>();
        st.push(root);

        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); i++) {
            int preorderVal = preorder[i];
            auto node = st.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                st.push(node->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[inorderIndex]) {
                    node = st.top();
                    st.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                st.push(node->right);
            }

            outSt(st);
        }
        return root;
    }

private:
    void outSt(stack<TreeNode *> st) {
        vector<int> res;
        while (!st.empty()) {
            res.emplace_back(st.top()->val);
            st.pop();
        }

        IC(res);
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
