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

    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        int left_value = 0;
        if (root->left && !root->left->left && !root->left->right)
            left_value = root->left->val;

        return left_value + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

    // iterate, stack
    int sumOfLeftLeaves_2(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*> sta;
        sta.push(root);
        int result = 0;
        while(!sta.empty()){
            TreeNode* node = sta.top();
            sta.pop();
            if(node->left && !node->left->left && !node->left->right)
                result += node->left->val;
            if(node->right) sta.push(node->right);
            if(node->left) sta.push(node->left);
        }
        return result;
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
    IC(solution->levelOrder(t3) == rel);

    int rel_2 = 24;
    IC(rel_2);
    IC(solution->sumOfLeftLeaves(t3) == rel_2);
    IC(solution->sumOfLeftLeaves_2(t3) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


