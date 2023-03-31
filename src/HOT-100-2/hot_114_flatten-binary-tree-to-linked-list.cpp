/**
-- question: 二叉树展开为链表
-- method:
 - [-] 记录前驱遍历
 - [ ] 前序遍历
 - [ ] 前序遍历和展开同步进行
 - [ ] 寻找前驱节点

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    void flatten(TreeNode *root) {
        if (!root) return;

        vector<TreeNode *> ord;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            auto node = st.top();
            st.pop();

            ord.emplace_back(node);
            if (node->right) {
                st.push(node->right);
                node->right = nullptr;
            }
            if (node->left) {
                st.push(node->left);
                node->left = nullptr;
            }
        }

        TreeNode *prev = ord.front();
//        prev->left = nullptr;
//        prev->right = nullptr;

        for (int i = 1; i < ord.size(); i++) {
//            ord[i]->left = nullptr;
//            ord[i]->right = nullptr;
            prev->right = ord[i];
            prev = ord[i];
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


