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


    // 2
private:
    // [left, right)
    TreeNode *traversal(vector<int> &nums, int left, int right) {
        if (left >= right) return nullptr;
        int maxValueIndex = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode *node = new TreeNode(nums[maxValueIndex]);
        node->left = traversal(nums, left, maxValueIndex);
        node->right = traversal(nums, maxValueIndex + 1, right);
        return node;

    }

public:
    TreeNode *constructMaximumBinaryTree_2(vector<int> &nums) {
        return traversal(nums, 0, nums.size());
    }
    // function end.
};


int main() {

    auto solution = new Solution();

    // code start


    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *node = solution->constructMaximumBinaryTree(nums);
    IC(solution->levelOrder(node));
    deleteTreeNode(node);

    TreeNode *node_2 = solution->constructMaximumBinaryTree_2(nums);
    IC(solution->levelOrder(node_2));
    deleteTreeNode(node_2);
    // code end

    delete solution;
    return 0;
}




