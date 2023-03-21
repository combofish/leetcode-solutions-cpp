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

private:
    void getLargest(TreeNode *root, vector<int> &result, int depth) {
        if (root == nullptr) return;
        if (depth == result.size()) result.emplace_back(root->val);
        result[depth] = std::max(result[depth], root->val);
        getLargest(root->left, result, depth + 1);
        getLargest(root->right, result, depth + 1);
    }

public:
    vector<int> largestValues_2(TreeNode *root) {
        vector<int> result;
        getLargest(root, result, 0);
        return result;
    }

    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> que;
        vector<int> res;
        if (nullptr != root) que.push(root);
        while (!que.empty()) {
            int _size = que.size();
            int n = INT_MIN;
            while (_size--) {
                TreeNode *node = que.front();
                que.pop();
                n = std::max(n, node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.emplace_back(n);
        }
        return res;
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

    vector<int> rel_2 = {3, 20, 15};
    IC(rel_2);
    IC(solution->largestValues((t3)) == rel_2);
    IC(solution->largestValues_2((t3)) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


