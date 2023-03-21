/**
-- question: 验证二叉搜索树
-- method:
 - [*] sort
 - [ ] recursive
 - [ ] iterate

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
        vector<int> record;
        traversal(root, record);
        IC(record);

        for (int i = 1; i < record.size(); i++)
            if (record[i - 1] >= record[i]) return false;

        return true;

    }

private:
    void traversal(TreeNode *node, vector<int> &vec) {
        if (node) {
            traversal(node->left, vec);
            vec.emplace_back(node->val);
            traversal(node->right, vec);
        }
    }

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


