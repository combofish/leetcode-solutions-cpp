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
    void traversal(TreeNode *node, vector<int> &vec) {
        if (node == nullptr) return;
        vec.push_back(node->val);
        traversal(node->left, vec);
        traversal(node->right, vec);
    }

    void traversal_postorder(TreeNode *pNode, vector<int> &vector1) {
        if (pNode == nullptr) return;
        traversal_postorder(pNode->left, vector1);
        traversal_postorder(pNode->right, vector1);
        vector1.emplace_back(pNode->val);
    }

    void traversal_inorder(TreeNode *pNode, vector<int> &vec) {
        if (pNode == nullptr) return;
        traversal_inorder(pNode->left, vec);
        vec.emplace_back(pNode->val);
        traversal_inorder(pNode->right, vec);
    }


public:
    // function start.
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    vector<int> preorderTraversal_2(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return result;
    }


    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal_postorder(root, res);
        return res;
    }

    vector<int> postorderTraversal_2(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }


    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal_inorder(root, res);
        return res;
    }

    vector<int> inorderTraversal_2(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> res;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }

        return res;

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    auto t3 = new TreeNode(3);
    auto t2 = new TreeNode(2, t3, nullptr);
    auto x = new TreeNode(1, nullptr, t2);

    //              1
    //      null         2
    //   null  null    3  null

    vector<int> res = solution->preorderTraversal(x);
    IC(res);

    IC(solution->postorderTraversal(x));
    IC(solution->inorderTraversal(x));

    // 迭代法
    IC(solution->preorderTraversal_2(x));
    IC(solution->postorderTraversal_2(x));
    IC(solution->inorderTraversal_2(x));

    delete t3;
    delete t2;
    delete x;

    // code end

    delete solution;
    return 0;
}


