/**
-- question: 把二叉搜索树转换为累加树
-- method:
 - [-] 反序中序遍历
 - [*] Morris 遍历

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
    TreeNode *convertBST(TreeNode *root) {
        if (root) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }


        return root;
    }

private:
    int sum = 0;

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto node = new TreeNode(4,
                             new TreeNode(1),
                             new TreeNode(6,
                                          new TreeNode(5),
                                          new TreeNode(7)
                             )
    );

    IC(treenode_tools::levelOrder(node));

    auto resNode = solution->convertBST(node);
    IC(treenode_tools::levelOrder(resNode));
    treenode_tools::deleteTreeNode(resNode);

    // code end

    return 0;
}


