/**
-- question: 二叉树的层序遍历
-- method:
 - [] recursive
 - [] iterate

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if(!root) return result;
        traversal(result, root, 1);
        return result;
    }

private:
    void traversal(vector<vector<int>> &rec, TreeNode *node, int depth) {
        if (rec.size() < depth) {
            rec.emplace_back(vector<int>(1, node->val));
        } else {
            rec[depth - 1].emplace_back(node->val);
        }

        if (node->left) traversal(rec, node->left, depth + 1);
        if (node->right) traversal(rec, node->right, depth + 1);

    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto t20 = new TreeNode(20, new TreeNode(25), new TreeNode(7));
    auto t3 = new TreeNode(3, new TreeNode(9), t20);

    vector<vector<int>> rel = {{3},
                               {9,  20},
                               {15, 7}};
    IC(solution->levelOrder(t3));

    deleteTreeNode(t3);

    // code end

    return 0;
}


