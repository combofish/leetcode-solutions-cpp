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

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1) return root2;
        else if (!root2) return root1;

        queue<TreeNode *> qu;
        qu.push(root1);
        qu.push(root2);

        while (!qu.empty()) {
            TreeNode *node1 = qu.front();
            qu.pop();
            TreeNode *node2 = qu.front();
            qu.pop();
            node1->val += node2->val;

            if (node1->left && node2->left) {
                qu.push(node1->left);
                qu.push(node2->left);
            }
            if (node1->right && node2->right) {
                qu.push(node1->right);
                qu.push(node2->right);
            }

            if (!node1->left && node2->left) node1->left = node2->left;
            if (!node1->right && node2->right) node1->right = node2->right;

        }

        return root1;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    // code end

    return 0;
}


