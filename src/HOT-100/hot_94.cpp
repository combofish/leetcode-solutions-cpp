/**
-- question: 二叉树的中序遍历
-- method: recursive
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
        traversal(result, root);
        return result;
    }

private:
    void traversal(vector<int> &vec, TreeNode *node) {
        if (node) {
            traversal(vec, node->left);
            vec.push_back(node->val);
            traversal(vec, node->right);
        }
    }
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


