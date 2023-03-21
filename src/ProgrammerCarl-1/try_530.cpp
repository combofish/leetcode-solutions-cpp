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


    // 1
private:
    vector<int> _vec;

    void getTreeNode(TreeNode *node) {
        if (!node) return;
        getTreeNode(node->left);
        _vec.push_back(node->val);
        getTreeNode(node->right);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        _vec.clear();
        getTreeNode(root);
        int result = INT_MAX;
        for (int i = 1; i < _vec.size(); i++) {
            result = std::min(result, _vec[i] - _vec[i - 1]);
        }
        return result;
    }

    // 2 iterate
    int getMinimumDifference_2(TreeNode *root) {
        stack<TreeNode *> sta;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        int result = INT_MAX;
        while (cur || !sta.empty()) {
            if (cur) {
                sta.push(cur);
                cur = cur->left;
            } else {
                cur = sta.top();
                sta.pop();
                if (pre) {
                    result = std::min(cur->val - pre->val, result);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return result;
    }


    // 3
private:
    TreeNode *_pre = nullptr;
    int _result = INT_MAX;

    void traversal(TreeNode *node) {
        if (!node) return;
        traversal(node->left);
        if (_pre) _result = std::min(_result, node->val - _pre->val);
        _pre = node;
        traversal(node->right);
    }

public:
    int getMinimumDifference_3(TreeNode *root) {
        _pre = nullptr;
        _result = INT_MAX;
        traversal(root);
        return _result;
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

    int rel = 2;
    IC(rel);
    IC(rel == solution->getMinimumDifference(node));
    IC(rel == solution->getMinimumDifference_2(node));
    IC(rel == solution->getMinimumDifference_3(node));


    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




