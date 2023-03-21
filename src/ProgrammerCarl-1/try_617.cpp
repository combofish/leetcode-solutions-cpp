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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root2->right = mergeTrees(root1->right, root2->right);
        return root1;
    }


    // 2
    TreeNode *mergeTrees_2(TreeNode *root1, TreeNode *root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        queue<TreeNode *> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();

            node1->val += node2->val;
            if(node1->right && node2->right){
                que.push(node1->right);
                que.push(node2->right);
            }
            if(node1->left && node2->left){
                que.push(node1->left);
                que.push(node2->left);
            }

            if (!node1->left && node2->left) node1->left = node2->left;
            if (!node1->right && node2->right) node1->right = node2->right;
        }
        return root1;
    }
    // function end.
};


int main() {

    auto solution = new Solution();

    // code start


    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *node = solution->constructMaximumBinaryTree(nums);
    IC(solution->levelOrder(node));

    vector<int> nums_2 = {1, 3, 2, 5};
    TreeNode *node_2 = solution->constructMaximumBinaryTree(nums_2);
    IC(solution->levelOrder(node_2));

//    TreeNode *node_rel = solution->mergeTrees(node, node_2);
//    IC(solution->levelOrder(node_rel));
    // [[11], [6, 5], [1, 4, 0], [1]]

    TreeNode *node_rel_2 = solution->mergeTrees_2(node, node_2);
    IC(solution->levelOrder(node_rel_2));

//    deleteTreeNode(node_rel);
//    deleteTreeNode(node_2);
//    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




