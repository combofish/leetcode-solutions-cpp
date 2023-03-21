/**
-- question: 二叉树展开为链表
-- method:
 - [ ] 前序遍历, recursive
 - [ ] 前序遍历, iterate
 - [] 前序遍历并展开单链表
 - [*] 寻找前驱节点  --- best ---

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    void flatten(TreeNode *root) {
        auto curr = root;
        while(curr){
            if(curr->left){
                auto next = curr->left;
                auto predecessor = next;
                while(predecessor->right){
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                IC(predecessor->val);

                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
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
