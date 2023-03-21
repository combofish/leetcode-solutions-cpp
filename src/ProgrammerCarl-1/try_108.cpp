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

    // 1 recursive
private:
    TreeNode *traversal(vector<int> &nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;

    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return traversal(nums, 0, nums.size() - 1);
    }


    // 2 iterate
    TreeNode *sortedArrayToBST_2(vector<int> &nums) {
        TreeNode *root = new TreeNode(0);
        queue<tuple<TreeNode *, int, int>> que;
        que.push({root, 0, nums.size() - 1});
        while (!que.empty()) {
            TreeNode *node;
            int left;
            int right;
            std::tie(node, left, right) = que.front();
            que.pop();

            int mid = left + (right - left) / 2;
            node->val = nums[mid];
            if (left <= mid - 1) {
                node->left = new TreeNode(0);
                que.push({node->left, left, mid - 1});
            }
            if (mid + 1 <= right) {
                node->right = new TreeNode(0);
                que.push({node->right, mid + 1, right});
            }
        }

        return root;

    }
    // function end.
};


int main() {

    auto solution = new Solution();

    // code start
    vector<int> rel = {-10, -3, 0, 5, 9};
    IC(rel);

    TreeNode *node = solution->sortedArrayToBST(rel);
    IC(solution->levelOrder(node));

    TreeNode *node_2 = solution->sortedArrayToBST_2(rel);
    IC(solution->levelOrder(node_2));


    deleteTreeNode(node_2);
    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




