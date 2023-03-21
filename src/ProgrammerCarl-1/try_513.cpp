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

    // iterate, que
    int findBottomLeftValue(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> que;
        que.push(root);

        TreeNode *result = root;
        while (!que.empty()) {
            int _size = que.size();
            while (_size--) {
                result = que.front();
                que.pop();
                if (result->right) que.push(result->right);
                if (result->left) que.push(result->left);
            }
        }
        return result->val;
    }

private:
    int max_depth = INT_MIN;
    int _result;

    void findLeft(TreeNode *root, int depth) {
        if (!root->left && !root->right) {
            if (depth > max_depth) {
                max_depth = depth;
                _result = root->val;
            }
        }

        if (root->left) findLeft(root->left, depth + 1);
        if (root->right) findLeft(root->right, depth + 1);
    }

public:
    int findBottomLeftValue_2(TreeNode *root) {
        if (!root) return 0;
        _result = 0;
        findLeft(root, 1);
        return _result;
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

    int rel_2 = t15->val;
    IC(solution->findBottomLeftValue(t3) == rel_2);
    IC(solution->findBottomLeftValue_2(t3) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


