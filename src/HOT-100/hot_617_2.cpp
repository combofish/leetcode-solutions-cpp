/**
-- question: 合并二叉树
-- method:
 - [] recursive
 - [] iterate

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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1) return root2;
        else if (!root2) return root1;

        TreeNode *root = root1;
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

        return root;

    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            int n = qu.size();
            vector<int> vec;
            while (n--) {
                TreeNode *node = qu.front();
                qu.pop();
                vec.emplace_back(node->val);

                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            result.emplace_back(vec);
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    TreeNode t5(5), t3(3), t2(2), t1(1);
    t1.right = &t3;
    t1.left = &t2;
    t3.left = &t5;

    auto root1 = &t1;
    TreeNode n2(2), n1(1), n4(4), n3(3), n7(7);
    n1.right = &n4;
    n3.left = &n7;
    n2.left = &n1;
    n2.right = &n3;

    auto root2 = &n2;

    TreeNode *result = solution->mergeTrees(root1, root2);

    auto res1 = solution->levelOrder(root1);
    auto res2 = solution->levelOrder(root2);
    auto res3 = solution->levelOrder(result);
    IC(res1, res2, res3);

    // code end

    return 0;
}


