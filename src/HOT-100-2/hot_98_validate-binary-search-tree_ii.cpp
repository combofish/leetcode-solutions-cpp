/**
-- question: 验证二叉搜索树
-- method:
 - [ ] 递归
 - [-] 中序遍历

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
    bool isValidBST(TreeNode *root) {

        stack<TreeNode *> st;
        long long inorder = (long long) INT_MIN - 1;

        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (root->val <= inorder) return false;
            inorder = root->val;
            root = root->right;
        }

        return true;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    auto n4 = new TreeNode(4, new TreeNode(3), new TreeNode(6));
    auto n5 = new TreeNode(5, new TreeNode(1), n4);

    IC(treenode_tools::levelOrder(n5));

    bool ans = false;
    IC(ans);

    IC(solution->isValidBST(n5));

    treenode_tools::deleteTreeNode(n5);
    // code end

    return 0;
}
