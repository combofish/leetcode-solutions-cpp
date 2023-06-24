/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include<algorithm>

class Solution {

    // function start.
public:
    int widthOfBinaryTree(TreeNode *root) {
        unsigned long long ans = 1;

        queue<pair<TreeNode *, unsigned long long>> qu;
        qu.emplace(root, 0l);

        while (!qu.empty()) {
            int sz = qu.size();
            unsigned long long max_val = 0, min_val = INT_MAX;
            while (sz-- > 0) {
                auto cur = qu.front();
                qu.pop();
                auto node = cur.first;
                auto idx = cur.second;
                IC(idx);

                max_val = std::max(max_val, idx);
                min_val = std::min(min_val, idx);

                if (node->left) qu.emplace(node->left, idx * 2 + 1);
                if (node->right) qu.emplace(node->right, idx * 2 + 2);
            }
            IC(ans, max_val, min_val);
            ans = std::max(ans, max_val - min_val + 1);
        }
        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto n3 = new TreeNode(3, new TreeNode(5), new TreeNode(3));;
    auto n2 = new TreeNode(2, nullptr, new TreeNode(9));
    auto root = new TreeNode(1, n3, n2);

    IC(treenode_tools::levelOrder(root));

    IC(solution->widthOfBinaryTree(root));
    treenode_tools::deleteTreeNode(root);
    // code end

    return 0;
}