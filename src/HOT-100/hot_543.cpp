/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O(N)
Space: O(Height)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int diameterOfBinaryTree(TreeNode *root) {
        ans = 1;
        traversal(root);
        return ans - 1;
    }

private:

    int ans;

    int traversal(TreeNode *node) {
        if (!node) return 0;
        int l = traversal(node->left);
        int r = traversal(node->right);
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    TreeNode n2(2), n1(1), n4(4), n3(3), n7(7);
    n1.right = &n4;
    n3.left = &n7;
    n2.left = &n1;
    n2.right = &n3;

    auto root1 = &n2;
    IC(solution->diameterOfBinaryTree(root1));

//



    // code end

    return 0;
}


