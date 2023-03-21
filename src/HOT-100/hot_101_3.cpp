/**
-- question: 对称二叉树
-- method: iterate
 - [ ] 递归
 - [*] stack
 - [ ] queue


--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode *> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode *t1 = st.top();
            st.pop();
            TreeNode *t2 = st.top();
            st.pop();

            if (!t1 && !t2) continue;
            if (t1 && t2) {
                IC(t1->val, t2->val);
                if (t1->val != t2->val) return false;

                st.push(t1->left);
                st.push(t2->right);

                st.push(t1->right);
                st.push(t2->left);
            } else return false;
        }
        return true;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto l2_1 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    auto l2_2 = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    auto l1 = new TreeNode(1, l2_1, l2_2);

    bool rel = true;
    IC(solution->isSymmetric(l1) == rel);

    deleteTreeNode(l1);

    // code end

    return 0;
}


