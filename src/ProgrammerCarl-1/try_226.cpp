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

    // function start.
    TreeNode *invertTree(TreeNode *root) {
        invert(root);
        return root;
    }

    TreeNode *invertTree_2(TreeNode *root) {
        stack<TreeNode *> sta;
        if (root != nullptr) sta.push(root);
        while (!sta.empty()) {
            TreeNode *node = sta.top();
            sta.pop();
            std::swap(node->right, node->left);
            if (node->right) sta.push(node->right);
            if (node->left) sta.push(node->left);
        }
        return root;
    }

private:
    void invert(TreeNode *node) {
        if (node == nullptr) return;
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;

        invert(node->left);
        invert(node->right);
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    auto t9 = new TreeNode(9);
    auto t15 = new TreeNode(15);
    auto t7 = new TreeNode(7);
    auto t20 = new TreeNode(20, t15, t7);
    auto t3 = new TreeNode(3, t9, t20);

    mat_t rel = {
            {3},
            {9,  20},
            {15, 7}
    };
    IC(rel);
    IC(solution->levelOrder(t3));

    TreeNode *invert_t3 = solution->invertTree(t3);
    TreeNode *invert_t3_2 = solution->invertTree_2(t3);
    IC(solution->levelOrder(invert_t3));
    IC(solution->levelOrder(invert_t3_2));

    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


