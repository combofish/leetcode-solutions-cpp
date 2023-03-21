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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return root;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            // root->val == key
            if (!root->left && !root->right) {
                // both nullptr
                delete root;
                return nullptr;
            } else if (!root->left) {
                // left nullptr, right not nullptr
                auto retNode = root->right;
                delete root;
                return retNode;
            } else if (!root->right) {
                auto retNode = root->left;
                delete root;
                return retNode;
            } else {
                // both not null
                TreeNode *cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode *tmp = root;
                root = root->right;
                delete tmp;
                return root;

            }
        }
        return root;
    }

    // 2 iterate
private:
    TreeNode *deleteOneTreeNode(TreeNode *root) {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            auto tmp = root->right;
            delete root;
            return tmp;
        } else if (!root->right) {
            auto tmp = root->left;
            delete root;
            return tmp;
        } else {
            TreeNode *cur = root->right;
            while (cur->left) cur = cur->left;
            cur->left = root->right;
            auto tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
    }

public:
    TreeNode *deleteNode_2(TreeNode *root, int key) {
        if (!root) return nullptr;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val < key) cur = cur->right;
            else cur = cur->left;
        }
        if (!pre) return deleteOneTreeNode(cur);
        if (pre->left && key == pre->left->val) pre->left = deleteOneTreeNode(cur);
        if (pre->right && key == pre->right->val) pre->right = deleteOneTreeNode(cur);
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


    int rel = 20;
    IC(rel);
    IC(solution->levelOrder(solution->deleteNode(node, rel)));
    IC(solution->levelOrder(solution->deleteNode_2(node, 27)));


    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




