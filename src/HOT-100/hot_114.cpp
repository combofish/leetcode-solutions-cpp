/**
-- question: 二叉树展开为链表
-- method:
 - [*] 前序遍历, recursive
 - [ ] 前序遍历, iterate
 - [] 前序遍历并展开单链表
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
        vector<TreeNode *> nums;
        preOrderTraversal(nums, root);

        TreeNode *dummyNode = new TreeNode(0);
        TreeNode *head = dummyNode;
        for (const auto &item: nums) {
            item->left = nullptr;
            head->right = item;
            head = head->right;
        }

        delete dummyNode;
    }

private:

    void preOrderTraversal(vector<TreeNode *> &nums, TreeNode *root) {
        if (root) {
            nums.emplace_back(root);
            preOrderTraversal(nums, root->left);
            preOrderTraversal(nums, root->right);
        }
    }

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


