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
        if (!root) return result;

        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty()) {
            int n = qu.size();
            result.emplace_back(vector<int>());
            while (n--) {
                TreeNode *tmp = qu.front();
                qu.pop();
                result.back().emplace_back(tmp->val);

                if (tmp->right) qu.push(tmp->right);
                if (tmp->left) qu.push(tmp->left);
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
    IC(solution->levelOrder(t3));

    deleteTreeNode(t3);

    // code end

    return 0;
}


