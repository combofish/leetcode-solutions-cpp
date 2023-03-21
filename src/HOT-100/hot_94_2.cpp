/**
-- question: 二叉树的中序遍历
-- method: iteration
 - []

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode* > st;

        while (!st.empty() || root) {
            if(root){
                st.push(root);
                root = root->left;
            }else{
                TreeNode* tmp = st.top();
                st.pop();
                result.emplace_back(tmp->val);
                root = tmp->right;
            }
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto t1 = new TreeNode(1);
    t1->right = new TreeNode(2);
    t1->right->left = new TreeNode(3);

    IC(solution->inorderTraversal(t1));

    deleteTreeNode(t1);

    // code end

    return 0;
}


