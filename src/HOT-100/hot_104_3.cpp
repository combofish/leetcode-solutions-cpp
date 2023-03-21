/**
-- question: 二叉树的最大深度
-- method:
 - [] recursive
 - [] recursive return
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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
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


