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

    // 1 recursive, return
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        return root;
    }

    // 2 iterate
    TreeNode *insertIntoBST_2(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *cur = root;
        TreeNode *pre = root;
        while (cur) {
            pre = cur;
            if (cur->val > val) cur = cur->left;
            else cur = cur->right;
        }

        TreeNode *node = new TreeNode(val);
        if (val < pre->val) pre->left = node;
        else pre->right = node;
        return root;
    }

    // 3 recursive void
private:
    TreeNode *_pPre;

    void traversal(TreeNode *node, int val) {
        if (!node) {
            TreeNode* newNode = new TreeNode(val);
            if (val > _pPre->val) _pPre->right = newNode;
            else _pPre->left = newNode;
            return;
        }
        _pPre = node;
        if (node->val > val) traversal(node->left, val);
        if (node->val < val) traversal(node->right, val);
    }

public:
    TreeNode *insertIntoBST_3(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);
        _pPre = root;
        traversal(root, val);
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


    int rel = 35;
    TreeNode *newNode = solution->insertIntoBST(node, rel);
    IC(rel, solution->levelOrder(newNode));
    IC(rel, solution->levelOrder(solution->insertIntoBST_2(node, 45)));
    IC(rel, solution->levelOrder(solution->insertIntoBST_3(node, 2)));

    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




