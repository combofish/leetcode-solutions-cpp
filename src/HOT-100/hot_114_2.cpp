/**
-- question: 二叉树展开为链表
-- method:
 - [ ] 前序遍历, recursive
 - [*] 前序遍历, iterate
 - [ ] 前序遍历并展开单链表
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
        if (!root) return;

        auto record = vector<TreeNode *>();
        auto st = stack<TreeNode *>();
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            record.emplace_back(node);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        auto dummyNode = new TreeNode(0);
        auto head = dummyNode;
        for (auto &item: record) {
            item->left = nullptr;
            head->right = item;
            head = head->right;
        }

        head = dummyNode->right;
        delete dummyNode;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto root = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    solution->flatten(root);

    auto res = treenode_tools::levelOrder(root);
    IC(res);

    treenode_tools::deleteTreeNode(root);


    // code end

    return 0;
}


