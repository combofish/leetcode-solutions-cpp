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

class Solution {
    TreeNode *getSuccessor(TreeNode *node) {
        auto succ = node->right;
        while (succ->left && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }

public:
    TreeNode *convertBST(TreeNode *root) {
        int prev = 0;
        auto curr = root;

        while (curr) {
            IC(curr->val);
            auto next = curr->right;
            if (next == nullptr) {
                curr->val += prev;
                prev = curr->val;

                curr = curr->left;
            } else {
                auto succ = getSuccessor(curr);
                IC(succ->val);

                if (succ->left == nullptr) {
                    succ->left = curr;
                    curr = curr->right; // node = node->left;
                } else {
                    succ->left = nullptr;
                    curr->val += prev;
                    prev = curr->val;
                    curr = curr->left;
                }

            }

        }

        return root;

    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n2 = new TreeNode(2, nullptr, new TreeNode(3));
    auto n1 = new TreeNode(1, new TreeNode(0), n2);

    auto n7 = new TreeNode(7, nullptr, new TreeNode(8));
    auto n6 = new TreeNode(6, new TreeNode(5), n7);
    auto n4 = new TreeNode(4, n1, n6);
    auto root = n4;

    IC(treenode_tools::levelOrder(root));

    auto res = solution->convertBST(root);
    IC(treenode_tools::levelOrder(res));

    treenode_tools::deleteTreeNode(res);

    // code end

    return 0;
}