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

    // 1
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root || root->val == val) return root;
        if (val < root->val) return searchBST(root->left, val);
        if (val > root->val) return searchBST(root->right, val);
        return nullptr;
    }


    // 2
    TreeNode *searchBST_2(TreeNode *root, int val) {
        while (root) {
            if (root->val == val) return root;
            if (root->val < val)
                root = root->left;
            else
                root = root->right;
        }

        return nullptr;
    }

    // function end.
};


int main() {

    auto solution = new Solution();

    // code start


    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *node = solution->constructMaximumBinaryTree(nums);
    IC(solution->levelOrder(node));


    TreeNode *rel = solution->searchBST(node, 6);
    IC(solution->levelOrder(rel));

    TreeNode *rel_2 = solution->searchBST_2(node, 6);
    IC(solution->levelOrder(rel_2));

    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




