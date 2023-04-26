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
    TreeNode *treeToDoublyList(TreeNode *root) {
        if (root == nullptr) return root;
        vector<TreeNode *> rec;
        auto node = root;
        stack<TreeNode *> st;

        while (node != nullptr || !st.empty()) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                rec.emplace_back(node);
                node = node->right;
            }
        }

        auto prev = rec.back();
        for (auto &item: rec) {
            prev->right = item;
            item->left = prev;
            prev = item;
        }

        return rec.front();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto n2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    auto n4 = new TreeNode(4, n2, new TreeNode(5));

    IC(treenode_tools::levelOrder(n4));

    auto ans = solution->treeToDoublyList(n4);

    for (int i = 0; i < 5; i++) {
        IC(ans->val, ans->right->val, ans->left->val);
        ans = ans->right;
    }

    cout << endl;
    IC();

    // code end

    return 0;
}