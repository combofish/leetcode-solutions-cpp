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
    typedef pair<int, int> p2;

    TreeNode *traversal(vector<int> &inorder, p2 inRange, vector<int> &preorder, p2 preRange) {
        if (preRange.first == preRange.second) return nullptr;

        int rootValue = preorder[preRange.first];
        TreeNode *root = new TreeNode(rootValue);

        if (preRange.second - preRange.first == 1) return root;
        int delimiterIndex;
        for (delimiterIndex = inRange.first; delimiterIndex < inRange.second; delimiterIndex++)
            if (inorder[delimiterIndex] == rootValue) break;

        root->left = traversal(
                inorder, {inRange.first, delimiterIndex},
                preorder, {preRange.first+1, preRange.first + delimiterIndex - inRange.first+1}
        );

        root->right = traversal(
                inorder, {delimiterIndex + 1, inRange.second},
                preorder, {preRange.first + delimiterIndex - inRange.first+1, preRange.second}
        );
        return root;


    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (0 == preorder.size() || 0 == inorder.size()) return nullptr;
        return traversal(inorder, {0, inorder.size()},
                         preorder, {0, preorder.size()});
    }
// function end.
};


int main() {

    auto solution = new Solution();

    // code start
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    IC(preorder, inorder);

    TreeNode *node = solution->buildTree(preorder, inorder);
    IC(solution->levelOrder(node));

    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




