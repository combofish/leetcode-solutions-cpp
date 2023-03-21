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

    // iterate, stack
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;
        bool result = false;
        stack<TreeNode *> sta;
        stack<int> sta_int;
        sta.push(root);
        sta_int.push(root->val);
        while (!sta.empty()) {
            TreeNode *node = sta.top();
            sta.pop();
            int tmp = sta_int.top();
            sta_int.top();

            if (!node->left && !node->right) {
                result = result || tmp == targetSum;
                IC(result);
                IC(tmp);
                outln(tmp);
            }
            if (node->left) {
                sta.push(node->left);
                sta_int.push(node->left->val + tmp);
            }
            if (node->right) {
                sta.push(node->right);
                sta_int.push(node->right->val + tmp);
            }


        }

        return result;
    }

    //
private:
    bool _result;

    void sumPath(TreeNode *node, int val) {
        if (!node->left && !node->right) {
            _result = _result || val == 0;
        }
        if (node->left) sumPath(node->left, val - node->left->val);
        if (node->right) sumPath(node->right, val - node->right->val);
    }

public:
    bool hasPathSum_2(TreeNode *root, int targetSum) {
        if (!root) return false;
        _result = false;
        sumPath(root, targetSum - root->val);
        return _result;
    }


    // 3
    bool hasPathSum_3(TreeNode *root, int targetSum) {
        if (!root) return false;
        queue<pair<TreeNode *, int>> que;
        que.push({root, targetSum - root->val});
        bool result = false;
        while (!que.empty()) {
            TreeNode *node = que.front().first;
            int val = que.front().second;
            if (!node->right) que.push({node->right, val - node->right->val});
            if (!node->left) que.push({node->left, val - node->left->val});
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

    bool rel_2 = true;
    IC(solution->hasPathSum(t3, 30) == rel_2);
    IC(solution->hasPathSum_2(t3, 30) == rel_2);
    IC(solution->hasPathSum_3(t3, 30) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


