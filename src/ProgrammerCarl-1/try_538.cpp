/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> que;
        vector<vector<int>> result;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int _size = que.size();
            vector<int> vec;
            while (_size--) {
                TreeNode *t = que.front();
                que.pop();
                vec.emplace_back(t->val);
                if (t->left) que.push(t->left);
                if (t->right) que.push(t->right);
            }
            result.push_back(vec);
        }
        return result;
    }

    // 1
private:
    int _pre;
    void traversal(TreeNode* cur){
        if(!cur) return;
        traversal(cur->right);
        cur->val += _pre;
        _pre = cur->val;
        traversal(cur->left);
    }
public:
    TreeNode *convertBST(TreeNode *root) {
        _pre = 0;
        traversal(root);
        return root;
    }


    // 2
private:
    int _pre_2;
    void traversal_2(TreeNode* node){
        if(!node) return;
        stack<TreeNode*> sta;

        TreeNode* cur = node;
        while(cur || !sta.empty()){
            if(cur){
                sta.push(cur);
                cur = cur->right;
            }else{
                cur = sta.top();
                sta.pop();
                cur->val += _pre_2;
                _pre_2 = cur->val;
                cur = cur->left;
            }
        }

    }
public:
    TreeNode* convertBST_2(TreeNode* root) {
        _pre_2 = 0;
        traversal_2(root);
        return root;
    }
    // function end.
};


int main() {

    auto solution = new Solution();

    // code start
    auto t9 = new TreeNode(9);
    auto t15 = new TreeNode(15);
    auto t27 = new TreeNode(27);
    auto t20 = new TreeNode(20, t15, t27);
    auto t13 = new TreeNode(13, t9, t20);
    auto node = t13;


    IC(solution->levelOrder(node));

    IC(solution->levelOrder(solution->convertBST(node)));
    IC(solution->levelOrder(solution->convertBST_2(node)));


    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




