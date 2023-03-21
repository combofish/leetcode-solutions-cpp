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
    /**
     * recursive
     * @param root
     * @return
     */
    int getHeight(TreeNode *root) {
        if (!root) return 0;
        int left_height = getHeight(root->left);
        if (-1 == left_height) return left_height;
        int right_height = getHeight(root->right);
        if (-1 == right_height) return right_height;

        if (std::abs(left_height - right_height) > 1) {
            return -1;
        } else {
            return 1 + std::max(left_height, right_height);
        }
    }

public:
    bool isBalanced(TreeNode *root) {
        return getHeight(root) != -1;
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

    bool rel_2 = true;
    IC(rel_2);

    IC(solution->isBalanced(t3) == rel_2);

    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


