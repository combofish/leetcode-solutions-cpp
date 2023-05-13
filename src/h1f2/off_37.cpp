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
#include <random>
class Solution {

    // function start.
public:

private:
    // function end.
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "None,";

        string ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            auto node = st.top();
            st.pop();

            if(node != nullptr){
                ans += std::to_string(node->val) + ',';
            }else{
                ans += "None,";
            }

            st.push(node->right);
            st.push(node->left);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::list<string> vec;
        string tmp;
        for(auto &c: data){
            if(c == ','){
                vec.emplace_back(tmp);
                tmp.clear();
            }else{
                tmp.push_back(c);
            }
        }

        return rDeserialize(vec);
    }
private:
    TreeNode* rDeserialize(std::list<string> &rec){
        if(rec.front() == "None"){
            rec.erase(rec.begin());
            return nullptr;
        }

        auto root = new TreeNode(std::stoi(rec.front()));
        rec.erase(rec.begin());
        root->left = rDeserialize(rec);
        root->right = rDeserialize(rec);
        return root;
    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n3 = new TreeNode(3, new TreeNode(4), new TreeNode(5));
    auto n1 = new TreeNode(1, new TreeNode(2), n3);

    IC(treenode_tools::levelOrder(n1));


    treenode_tools::deleteTreeNode(n1);


    srand((unsigned )time(nullptr));

    IC(rand());
    IC(std::rand());

    for(int i = 0; i< 10; i++){
        IC(rand() % 6 + 0);
    }

    // code end

    return 0;
}