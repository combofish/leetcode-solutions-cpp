/**
-- question: 打家劫舍 III
-- method:
 - [*] 动态规划

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <valarray>

class Solution {

    // function start.
public:
    int rob(TreeNode *root) {
        auto res = to_rob(root);

        return std::max(res.first, res.second);
    }

private:
    pair<int, int> to_rob(TreeNode *root) {
        // pair<int, int> rob, disRob

        if (!root) return {0, 0};

        auto l = to_rob(root->left);
        auto r = to_rob(root->right);

        auto selected = root->val + l.second + r.second;
        auto not_selected = std::max(l.first, l.second) + std::max(r.second, r.first);
        return {selected, not_selected};
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n2 = new TreeNode(2, nullptr, new TreeNode(3));
    auto n3 = new TreeNode(3, nullptr, new TreeNode(1));
    auto root = new TreeNode(3, n2, n3);

    int ans = 7;

    IC(treenode_tools::levelOrder(root), ans);
    IC(solution->rob(root));

    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}
