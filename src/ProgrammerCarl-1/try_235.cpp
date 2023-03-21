/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> que;
        vector<vector<int>> result;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int _size = que.size();
            vector<int> vec;
            while (_size--) {
                TreeNode *t = que.front();
                que.pop();
                vec.emplace_back(t->val);
                if (t->left) que.push(t->left);
                if (t->right) que.push(t->right);
            }
            result.push_back(vec);
        }
        return result;
    }

    // 1 iterate
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while (root) {
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }

    // 2 recursive
    TreeNode *lowestCommonAncestor_2(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor_2(root->right, p, q);
        } else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor_2(root->left, p, q);
        } else {
            return root;
        }
    }
    // function end.
};


int main() {

    auto solution = new Solution();

    // code start
    auto t9 = new TreeNode(9);
    auto t15 = new TreeNode(15);
    auto t27 = new TreeNode(27);
    auto t20 = new TreeNode(20, t15, t27);
    auto t13 = new TreeNode(13, t9, t20);
    auto node = t13;


    IC(solution->levelOrder(node));

    vector<int> rel = {13, 20};
    IC(rel);

    IC(solution->lowestCommonAncestor(node, t9, t15) == t13);
    IC(solution->lowestCommonAncestor_2(node, t9, t15) == t13);


    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




