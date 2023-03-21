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

    // maxDepth, recursive
private:
    int getDepth(TreeNode *node) {
        if (!node) return 0;
        int left_n = getDepth(node->left);
        int right_n = getDepth(node->right);
        return 1 + std::max(left_n, right_n);
    }

public:
    int maxDepth(TreeNode *root) {
        return getDepth(root);
    }

    // maxDepth_2
private:
    int _res;

    void getDepth_2(TreeNode *node, int depth) {
        _res = std::max(_res, depth);

        if (node->left == nullptr && node->right == nullptr) return;

        if (node->left) {
            getDepth_2(node->left, depth + 1);
        }

        if (node->right) {
            getDepth_2(node->right, depth + 1);
        }
    }

public:
    int maxDepth_2(TreeNode *node) {
        _res = 0;
        if (!node) return _res;
        getDepth_2(node, 1);
        return _res;
    }


    // maxDepth_3, iteration, que
public:
    int maxDepth_3(TreeNode *node) {
        if (!node) return 0;
        queue<TreeNode *> que;
        que.push(node);
        int res = 0;
        while (!que.empty()) {
            int _size = que.size();
            res++;
            while (_size--) {
                TreeNode *node1 = que.front();
                que.pop();

                if (node1->left) que.push(node1->left);
                if (node1->right) que.push(node1->right);
            }
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

    int rel_2 = 3;
    IC(rel_2);
    IC(solution->maxDepth(t3) == rel_2);
    IC(solution->maxDepth_2(t3) == rel_2);
    IC(solution->maxDepth_3(t3) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


