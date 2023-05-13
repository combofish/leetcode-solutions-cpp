/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    int kthLargest(TreeNode* root, int k) {
        auto node = root;
        stack<TreeNode*> st;
        while(node != nullptr || !st.empty()){
            if(node != nullptr){
                st.push(node);
                node = node->right;
            }else{
                node = st.top();
                st.pop();
                k--;
                if(k==0) return node->val;
                node = node->left;
            }
        }

        return -1;

    }
private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n2 = new TreeNode(2, new TreeNode(1), nullptr);
    auto n3 = new TreeNode(3, n2, new TreeNode(4));
    auto n4 = new TreeNode(5, n3, new TreeNode(6));

    IC(treenode_tools::levelOrder(n4));

    int k = 3;
    IC(solution->kthLargest(n4, k));

    treenode_tools::deleteTreeNode(n4);

    // code end

    return 0;
}