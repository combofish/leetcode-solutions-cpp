/**
-- question: 验证二叉搜索树
-- method:
 - [ ] sort
 - [ ] recursive
 - [*] iterate

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
    //

    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> st;
        TreeNode *pre;
        TreeNode *cur = root;

        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode *tmp = st.top();
                st.pop();

                if (pre && pre->val >= tmp->val) return false;
                pre = tmp;
                cur = tmp->right;
            }
        }
        return true;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto root = new TreeNode(5, new TreeNode(1), nullptr);
    auto t4 = new TreeNode(4, new TreeNode(3), new TreeNode(6));
    root->right = t4;

    bool rel = false;
    IC(solution->isValidBST(root) == rel);

    deleteTreeNode(root);


//    IC(INT_MIN, INT_MAX);

//    long iMin = -std::pow(2, 31);
//    long iMax = std::pow(2, 31) - 1;
//    IC(iMin, iMax);


    // code end

    return 0;
}


