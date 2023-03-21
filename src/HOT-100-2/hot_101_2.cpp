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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode *> st;
        st.push(root->left);
        st.push(root->right);

        while (!st.empty()) {
            auto ln = st.top();
            st.pop();
            auto rn = st.top();
            st.pop();

            if (!ln && !rn) continue;
            else if (!ln && rn)
                return false;
            else if (ln && !rn)
                return false;
            else {
	      if(ln->val != rn->val) return false;
                st.push(ln->left);
                st.push(rn->right);
                st.push(ln->right);
                st.push(rn->left);
            }
        }


        return true;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    bool ans = true;

    IC(treenode_tools::levelOrder(node));
    IC(ans);

    IC(solution->isSymmetric(node));
    treenode_tools::deleteTreeNode(node);

    // code end

    return 0;
}
