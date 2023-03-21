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
private:
    void order(TreeNode *cur, vector<vector<int>> &result, int depth) {
        if (cur == nullptr) return;
        if (depth == result.size()) result.emplace_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }

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

    vector<vector<int>> levelOrder_2(TreeNode *root) {
        vector<vector<int>> result;
        order(root, result, 0);
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
    IC(solution->levelOrder_2(t3) == rel);

    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;

    // code end

    delete solution;
    return 0;
}


