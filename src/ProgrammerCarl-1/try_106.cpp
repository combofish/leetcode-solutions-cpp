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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0) return nullptr;

        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);

        if (postorder.size() == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
            if (inorder[delimiterIndex] == rootValue) break;

        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }


public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || 0 == postorder.size()) return nullptr;
        return traversal(inorder, postorder);
    }


    // 2
private:
    typedef pair<int, int> p2;

    TreeNode *traversal_2(vector<int> &inorder, p2 inRange, vector<int> &postorder, p2 outRange) {
        if (outRange.second == outRange.first) return nullptr;

        int rootValue = postorder[outRange.second - 1];
        TreeNode *root = new TreeNode(rootValue);

        if (outRange.second - outRange.first == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inRange.first; delimiterIndex < inRange.second; delimiterIndex++)
            if (inorder[delimiterIndex] == rootValue) break;

        p2 leftInorderRange = std::make_pair(inRange.first, delimiterIndex);
        p2 rightInorderRange = std::make_pair(delimiterIndex + 1, inRange.second);

        p2 leftPostorderRange = std::make_pair(outRange.first, outRange.first + delimiterIndex - inRange.first);
        p2 rightPostorderRange = std::make_pair(outRange.first + (delimiterIndex - inRange.first), outRange.second - 1);

        root->right = traversal_2(inorder, rightInorderRange, postorder, rightPostorderRange);
        root->left = traversal_2(inorder, leftInorderRange, postorder, leftPostorderRange);

        return root;
    }


public:

    TreeNode *buildTree_2(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal_2(inorder, {0, inorder.size()},
                           postorder, {0, postorder.size()});
    }
// function end.
};


int main() {

    auto solution = new Solution();

    // code start
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    IC(inorder, postorder);

//    TreeNode *node = solution->buildTree(inorder, postorder);
//    IC(solution->levelOrder(node));

    TreeNode *node_2 = solution->buildTree_2(inorder, postorder);
    IC(solution->levelOrder(node_2));

    deleteTreeNode(node_2);
//    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




