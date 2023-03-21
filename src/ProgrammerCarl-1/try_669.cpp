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

    // 1 recursive
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) {
            TreeNode *node = trimBST(root->right, low, high);
            // delete root;
            return node;
        }
        if (root->val > high) {
            TreeNode *node = trimBST(root->left, low, high);
            // delete root;
            return node;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }

    // 2 iterate
    TreeNode *trimBST_2(TreeNode *root, int low, int high) {
        if (!root) return nullptr;
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right;
            else root = root->left;
        }

        TreeNode* cur = root;
        while (cur != nullptr){
            while(cur->left && cur->left->val < low){
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        // process right
        cur = root;
        while(cur != nullptr){
            while(cur->right && cur->right->val > high){
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;

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


    IC(solution->levelOrder(solution->trimBST(node, 0, 26)));
    IC(solution->levelOrder(solution->trimBST_2(node, 10, 26)));


    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




