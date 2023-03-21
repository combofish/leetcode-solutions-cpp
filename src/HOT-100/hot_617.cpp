/**
-- question: 合并二叉树
-- method:
 - [] recursive

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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1) return root2;
        else if (!root2) return root1;
        else {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    TreeNode t5(5), t3(3), t2(2), t1(1);
    t1.right = &t3;
    t1.left = &t2;
    t3.left = &t5;

    auto root1 = &t1;
    TreeNode n2(2), n1(1), n4(4), n3(3), n7(7);
    n1.right = &n4;
    n3.left = &n7;
    n2.left = &n1;
    n2.right = &n3;

    auto root2 = &n2;

    TreeNode *result = solution->mergeTrees(root1, root2);

    middleOrder(root1);
    middleOrder(root2);
    middleOrder(result);


    // code end

    return 0;
}


