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

    // iterate, queue
    /**
     * Time: O(n)
     * Space: O(n)
     * @param root
     * @return
     */
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> que;
        que.push(root);
        int res = 0;
        while (!que.empty()) {
            int _size = que.size();
            while (_size--) {
                TreeNode *node = que.front();
                que.pop();
                res++;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }

    // 2, recursive
    int countNodes_2(TreeNode *root) {
        if (!root) return 0;
        int left_n = countNodes_2(root->left);
        int right_n = countNodes_2(root->right);
        return 1 + left_n + right_n;
    }

    // 3
private:
    int _count_n;

    void count_number(TreeNode *root, int depth) {
        _count_n++;
        if (root->left) count_number(root->left, depth + 1);
        if (root->right) count_number(root->right, depth + 1);
    }

public:
    int countNodes_3(TreeNode *root) {
        if (!root) return 0;
        _count_n = 0;
        count_number(root, 1);
        return _count_n;
    }

    // 4
public:
    /**
     * Time: O(log n * log n)
     * Space: O(log n)
     * @param root
     * @return
     */
    int countNodes_4(TreeNode* root){
        if(!root) return 0;
        int left_n = 0;
        int right_n = 0;
        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;
        while(left_node){
            left_node = left_node->left;
            left_n++;
        }

        while(right_node){
            right_node = right_node->right;
            right_n++;
        }

        if(right_n == left_n){
            return (2 << left_n) - 1;
        }

        return 1 + countNodes_4(root->left) + countNodes_4(root->right);
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

    int rel_2 = 5;
    IC(rel_2);
    IC(solution->countNodes(t3) == rel_2);
    IC(solution->countNodes_2(t3) == rel_2);
    IC(solution->countNodes_3(t3) == rel_2);
    IC(solution->countNodes_4(t3) == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


