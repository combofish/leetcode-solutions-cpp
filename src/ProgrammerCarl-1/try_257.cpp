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
    vector<string> _result;

    void getPaths(TreeNode *root, string path_str) {
        if (root->left == nullptr && root->right == nullptr) {
            _result.push_back(path_str);
            return;
        }

        if (root->left) getPaths(root->left, path_str + "->" + std::to_string(root->left->val));
        if (root->right) getPaths(root->right, path_str + "->" + std::to_string(root->right->val));
    }

public:
    /**
     * recursive
     * @param root
     * @return
     */
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) return _result;
        getPaths(root, std::to_string(root->val));
        return _result;
    }

    /**
     * iterate, stack_node, stack_string
     * @param root
     * @return
     */
    vector<string> binaryTreePaths_2(TreeNode *root) {
        vector<string> result;
        if (!root) return result;

        stack<TreeNode *> sta_node;
        stack<string> sta_str;

        sta_node.push(root);
        sta_str.push(std::to_string(root->val));

        while (!sta_node.empty()) {
            TreeNode *node = sta_node.top();
            sta_node.pop();
            string str = sta_str.top();
            sta_str.pop();

            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(str);
            }

            if(node->left) {
                sta_node.push(node->left);
                sta_str.push(str + "->" + std::to_string(node->left->val));
            }

            if(node->right){
                sta_node.push(node->right);
                sta_str.push(str + "->" + std::to_string(node->right->val));
            }

        }
        return result;
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

    vector<string> rel_2 = {"3->9", "3->20->15", "3->20->7"};
    IC(rel_2);

    vector<string> rel_3 = solution->binaryTreePaths(t3);
    IC(rel_3, rel_3 == rel_2);

    vector<string> rel_4 = solution->binaryTreePaths_2(t3);
    IC(rel_4, rel_4 == rel_2);


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


