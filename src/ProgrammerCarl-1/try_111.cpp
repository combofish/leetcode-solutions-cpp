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

    // recursive
    int minDepth(TreeNode *root) {
        if (!root) return 0;

        if (root->right == nullptr && root->left != nullptr)
            return 1 + minDepth(root->left);

        if (root->right != nullptr && root->left == nullptr)
            return 1 + minDepth(root->right);

        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }

    //
private:
    int _min_depth;

    void getMinDepth(TreeNode *root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            _min_depth = std::min(_min_depth, depth);
            return;
        }

        if (root->left) getMinDepth(root->left, depth + 1);
        if (root->right) getMinDepth(root->right, depth + 1);
    }

public:
    int minDepth_2(TreeNode *root) {

        if (!root) return 0;
        _min_depth = INT_MAX;
        getMinDepth(root, 1);
        return _min_depth;
    }

    // iterate
    int minDepth_3(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> que;
        que.push(root);

        int min_depth = 0;
        while (!que.empty()) {
            int _size = que.size();
            min_depth++;
            while (_size--) {
                TreeNode *node = que.front();
                que.pop();

                if (node->right == nullptr && node->left == nullptr)
                    return min_depth;

                if (node->right) que.push(node->right);
                if (node->left) que.push(node->left);
            }
        }
        return min_depth;
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

    int rel_2 = 2;
    IC(rel_2);
    IC(solution->minDepth(t3) == rel_2);
    IC(solution->minDepth_2(t3) == rel_2);
    IC(solution->minDepth_3(t3) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


