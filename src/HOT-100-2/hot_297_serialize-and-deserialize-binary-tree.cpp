/**
-- question: 二叉树的序列化与反序列化
-- method:
 - [-] 深度优先搜索

--result:

-- analyse:
Time: O(n)
Space: O(n)
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
    string serialize(TreeNode *root) {
        string ans;
        rSerialize(root, ans);
        return ans;
    }

    TreeNode *deserialize(string data) {
        std::list<string> dataArray;
        string str;
        for (const auto &ch: data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }

        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }

        IC(dataArray);
        return rDeserialize(dataArray);
    }

private:
    void rSerialize(TreeNode *node, string &str) {
        if (node == nullptr) {
            str += "null,";
        } else {
            str += std::to_string(node->val) + ',';
            rSerialize(node->left, str);
            rSerialize(node->right, str);
        }
    }

    TreeNode *rDeserialize(std::list<string> &dataArray) {
        if (dataArray.front() == "null") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        auto root = new TreeNode(std::stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rDeserialize(dataArray);
        root->right = rDeserialize(dataArray);
        return root;
    }

};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n3 = new TreeNode(3, new TreeNode(4), new TreeNode(5));
    auto n1 = new TreeNode(1, new TreeNode(2), n3);

    IC(treenode_tools::levelOrder(n1));

    auto codec = std::make_shared<Codec>();
    auto res = codec->serialize(n1);
    IC(res);

    auto res_node = codec->deserialize(res);
    IC(treenode_tools::levelOrder(res_node));

    treenode_tools::deleteTreeNode(res_node);
    treenode_tools::deleteTreeNode(n1);


    // code end

    return 0;
}
