/**
-- question: 二叉树的最大深度
-- method:
 - [] recursive
 - [] iterate
 - [] recursive return

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
    int maxDepth(TreeNode *root) {
        int result = 0;
        if (!root) return result;

        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            int n = qu.size();
            result++;
            while (n--) {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
        }

        return result;
    }

private:

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

    int res = 3;
    IC(rel, res);

    IC(solution->maxDepth(t3));

    deleteTreeNode(t3);

    // code end

    return 0;
}


