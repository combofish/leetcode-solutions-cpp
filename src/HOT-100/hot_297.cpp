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

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string result;
        traversalSerialize(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        std::list<string> dataArray;
        string str;
        for (const auto &item: data) {
            if (item == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(item);
            }
        }

        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }

        IC(dataArray);
        return traversalDeserialize(dataArray);
    }

private:
    void traversalSerialize(TreeNode *node, string &str) {
        if (!node) {
            str += "null,";
        } else {
            str += std::to_string(node->val) + ",";
            traversalSerialize(node->left, str);
            traversalSerialize(node->right, str);
        }
    }

    TreeNode *traversalDeserialize(list<string> &dataArray) {
        if (dataArray.front() == "null") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode *root = new TreeNode(std::stoi(dataArray.front()));

//        IC(root->val);

        dataArray.erase(dataArray.begin());
        root->left = traversalDeserialize(dataArray);
        root->right = traversalDeserialize(dataArray);
        return root;
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


    string test = "[1,null,2,null,null,]";
    auto node11 = treenode_tools::string2TreeNode(test);

    IC(test, treenode_tools::serialize(node11));
    treenode_tools::deleteTreeNode(node11);
    // code end

    return 0;
}


