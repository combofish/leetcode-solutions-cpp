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

private:
    // function end.
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ans;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (node) {
                ans += std::to_string(node->val) + ',';
                st.push(node->right);
                st.push(node->left);
            } else {
                ans += "None,";
            }
        }
        return ans;
    }

private:
    TreeNode *rDeserialize(std::list<string> &lst) {
        // IC(lst);
        if (lst.front() == "None") {
            lst.erase(lst.begin());
            return nullptr;
        }
        auto node = new TreeNode(std::stoi(lst.front()));
        lst.erase(lst.begin());
        node->left = rDeserialize(lst);
        node->right = rDeserialize(lst);

        return node;
    }

public:
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        string tmp;
        std::list<string> lst;
        for (auto &c: data) {
            if (c == ',') {
                lst.emplace_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }
        IC(lst);
        return rDeserialize(lst);
    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n3 = new TreeNode(3, new TreeNode(4), new TreeNode(5));
    auto n1 = new TreeNode(1, new TreeNode(2), n3);
    auto root = n1;
    IC(treenode_tools::levelOrder(n1));

    auto codec = new Codec();
    auto str = codec->serialize(root);

    IC(str);

    treenode_tools::deleteTreeNode(root);

    auto res = codec->deserialize(str);

    IC(treenode_tools::levelOrder(res));
    delete codec;

    treenode_tools::deleteTreeNode(res);
    // code end

    return 0;
}