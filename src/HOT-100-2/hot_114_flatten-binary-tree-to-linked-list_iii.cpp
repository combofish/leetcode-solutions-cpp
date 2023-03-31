/**
-- question: 二叉树展开为链表
-- method:
 - [ ] 记录前驱遍历
 - [-] 前序遍历
 - [ ] 前序遍历和展开同步进行
 - [ ] 寻找前驱节点

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    void flatten(TreeNode *root) {
        vector<TreeNode *> rec;
        stack<TreeNode *> st;

        auto node = root;
        while (node || !st.empty()) {
            while (node) {
                rec.emplace_back(node);
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }

        int n = rec.size();
        for (int i = 1; i < n; i++) {
            auto prev = rec[i - 1];
            prev->left = nullptr;
            prev->right = rec[i];
        }
    }

private:


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n2 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    auto n5 = new TreeNode(5, nullptr, new TreeNode(6));

    auto n1 = new TreeNode(1, n2, n5);

    IC(treenode_tools::levelOrder(n1));

    solution->flatten(n1);

    IC(treenode_tools::levelOrder(n1));
    treenode_tools::deleteTreeNode(n1);

    // code end

    return 0;
}


