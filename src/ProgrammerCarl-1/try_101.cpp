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
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left->val != right->val) return false;

        bool inSide = compare(left->right, right->left);
        bool outSide = compare(left->left, right->right);
        return inSide && outSide;
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (nullptr == root) return true;
        return compare(root->left, root->right);
    }

    bool isSymmetric_2(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode *left = que.front();
            que.pop();
            TreeNode *right = que.front();
            que.pop();

            if (!left && !right) continue;
            if (!left || !right || (left->val != right->val))
                return false;

            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }

        return true;
    }

    bool isSymmetric_3(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode *> sta;
        sta.push(root->left);
        sta.push(root->right);
        while (!sta.empty()) {
            TreeNode *left = sta.top();
            sta.pop();
            TreeNode *right = sta.top();
            sta.pop();

            if (!left && !right) continue;
            if (!left || !right || (left->val != right->val)) return false;

            sta.push(left->left);
            sta.push(right->right);
            sta.push(left->right);
            sta.push(right->left);
        }
        return true;
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

    bool rel_2 = false;
    IC(rel_2);
    IC(solution->isSymmetric(t3) == rel_2);
    IC(solution->isSymmetric_2(t3) == rel_2);
    IC(solution->isSymmetric_3(t3) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


