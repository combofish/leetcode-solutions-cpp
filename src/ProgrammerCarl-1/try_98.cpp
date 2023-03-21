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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        TreeNode *node = new TreeNode(0);
        if (1 == nums.size()) {
            node->val = nums[0];
            return node;
        }

        // find max
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }

        node->val = maxValue;
        if (maxValueIndex > 0) {
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        if (maxValueIndex < (nums.size() - 1)) {
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }

    // 1, turn to vector<int>
private:
    vector<int> _vec;

    void traversal(TreeNode *node) {
        if (!node) return;
        traversal(node->left);
        _vec.push_back(node->val);
        traversal(node->right);
    }

public:
    bool isValidBST(TreeNode *root) {
        _vec.clear();
        traversal(root);
        for (int i = 1; i < _vec.size(); i++) {
            if (_vec[i] <= _vec[i - 1]) return false;
        }
        return true;
    }

    // 2
private:
    TreeNode *_pre = nullptr;
public:
    bool isValidBST_2(TreeNode *root) {
        if (!root) return true;
        IC(root->val);

        bool left = isValidBST_2(root->left);
        if (_pre && _pre->val >= root->val) return false;
        _pre = root;
        bool right = isValidBST_2(root->right);
        return left && right;
    }

    // 3
    bool isValidBST_3(TreeNode *root) {
        stack<TreeNode *> sta;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur || !sta.empty()) {
            if (cur) {
                sta.push(cur);
                cur = cur->left;
            } else {
                cur = sta.top();
                sta.pop();
                if (pre && cur->val <= pre->val) return false;
                pre = cur;
                cur = cur->right;
            }
        }

        return true;
    }
    // function end.
};


int main() {

    auto solution = new Solution();

    // code start


    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *node = solution->constructMaximumBinaryTree(nums);
    IC(solution->levelOrder(node));


    bool rel = false;
    IC(rel);
    IC(rel == solution->isValidBST(node));
    IC(rel == solution->isValidBST_2(node));
    IC(rel == solution->isValidBST_3(node));


    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




