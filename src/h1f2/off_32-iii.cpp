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

class Solution {

    // function start.
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) return {};
        int flag = true;
        queue<TreeNode *> qu;
        qu.push(root);

        vector<vector<int>> ans;
        while (!qu.empty()) {
            int sz = qu.size();
            flag = !flag;
            vector<int> tmp;
            // IC(qu);
            out_qu(qu);
            IC(flag);

            while (sz--) {
                auto node = qu.front();
                qu.pop();
                tmp.emplace_back(node->val);

                if (flag == false) {
                    if (node->right) qu.push(node->right);
                    if (node->left) qu.push(node->left);
                } else {
                    if (node->left) qu.push(node->left);
                    if (node->right) qu.push(node->right);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }

private:
    void out_qu(queue<TreeNode *> qu) {
        vector<int> tmp;
        while (!qu.empty()) {
            tmp.push_back(qu.front()->val);
            qu.pop();
        }
        IC(tmp);
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto n20 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    auto n3 = new TreeNode(3, new TreeNode(9), n20);

    IC(treenode_tools::levelOrder(n3));


    vector<vector<int>> ans = {
            {3},
            {20, 9},
            {15, 7}
    };

    IC(ans);
    IC(solution->levelOrder(n3));

    treenode_tools::deleteTreeNode(n3);


    // code end

    return 0;
}