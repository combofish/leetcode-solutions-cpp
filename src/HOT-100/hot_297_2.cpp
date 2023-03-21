/**
-- question: 二叉树的序列化与反序列化
-- method:
 - []

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
    TreeNode *string2TreeNode(const std::string &str) {
        if (str.front() == '[' && str.back() == ']') {
            return deserialize(str.substr(1, str.size() - 2));
        } else {
            return deserialize(str);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "null,";

        string result;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (!node) result += "null,";
            else {
                result += std::to_string(node->val) + ",";
                st.push(node->right);
                st.push(node->left);
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data) {
        std::list<string> dataList;
        string tmpStr;
        for (const auto &item: data) {
            if (item == ',') {
                dataList.emplace_back(tmpStr);
                tmpStr.clear();
            } else {
                tmpStr.push_back(item);
            }
        }

        if (!tmpStr.empty()) {
            dataList.push_back(tmpStr);
            tmpStr.clear();
        }

        IC(dataList);
        return traversalDeserialize(dataList);
    }

private:
    TreeNode *traversalDeserialize(std::list<string> &dataList) {
        if (dataList.front() == "null") {
            dataList.erase(dataList.begin());
            return nullptr;
        }

        auto node = new TreeNode(std::stoi(dataList.front()));
        dataList.erase(dataList.begin());
        node->left = traversalDeserialize(dataList);
        node->right = traversalDeserialize(dataList);
        return node;
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

    /**
     *       2
     *    1     3
     *     4   7
     */

    auto root1 = &n2;

    auto str1 = solution->serialize(root1);


    IC(str1);

    auto root2 = solution->deserialize(str1);
    IC(treenode_tools::levelOrder(root2));
    treenode_tools::deleteTreeNode(root2);

    string t_str = "[1,null,null,]";
    IC(t_str);
    auto t_node = solution->string2TreeNode(t_str);
    IC(treenode_tools::levelOrder(t_node));
    treenode_tools::deleteTreeNode(t_node);


    // code end

    return 0;
}


