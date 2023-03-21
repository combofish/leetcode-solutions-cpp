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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        if (!root) return result;
        stack<tuple<TreeNode *, int, vector<int>>> sta;

        sta.push(std::make_tuple(root, targetSum - root->val, vector<int>{root->val}));
        while (!sta.empty()) {

            auto context = sta.top();
            sta.pop();

            auto node = std::get<0>(context);
            auto a_val = std::get<1>(context);
            auto a_res = std::get<2>(context);
//            IC(node, a_val, a_res);

            if (!node->left && !node->right) {
                if (a_val == 0) {
                    result.push_back(a_res);
//                    IC(node->val);
//                    IC(result);
                }
            }
            if (node->left) {
                a_res.push_back(node->left->val);
                sta.push(std::tuple<TreeNode *, int, vector<int>>(
                        node->left, a_val - node->left->val,
                        a_res
                ));
                a_res.pop_back();
            }
            if (node->right) {
                a_res.push_back(node->right->val);
                sta.push(std::tuple<TreeNode *, int, vector<int>>(
                        node->right, a_val - node->right->val,
                        a_res));
                a_res.pop_back();
            }
        }

        return result;

    }

    // 2
    vector<vector<int>> pathSum_2(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        if (!root) return result;
        std::stack<std::tuple<TreeNode *, int, vector<int>>> sta;
        sta.push(std::make_tuple(root, targetSum - root->val, vector<int>{root->val}));
        while (!sta.empty()) {
            TreeNode *node;
            int a_val;
            vector<int> a_res;
//            auto node;
//            auto a_val;
//            auto a_res;
            std::tie(node, a_val, a_res) = sta.top();
            sta.pop();
            IC(node, a_val, a_res);

            if (!node->left && !node->right) {
                if (0 == a_val) {
                    result.push_back(a_res);
                }
            }

            if (node->left) {
                a_res.push_back(node->left->val);
                // sta.push(std::tuple<TreeNode *, int, vector<int>>(node->left, a_val - node->left->val, a_res));
                // sta.push(std::make_tuple(node->left, a_val - node->left->val, a_res));
                sta.push({node->left, a_val - node->left->val, a_res});
                a_res.pop_back();
            }

            if (node->right) {
                a_res.push_back(node->right->val);
                // sta.push(std::tuple<TreeNode *, int, vector<int>>(node->right, a_val - node->right->val, a_res));
                // sta.push(std::make_tuple(node->right, a_val - node->right->val, a_res));
                sta.push({node->right, a_val - node->right->val, a_res});
                a_res.pop_back();
            }

        }
        return result;
    }


    // 3 recursive
private:
    vector<vector<int>> _result;
    vector<int> _path;

    void getPath(TreeNode *node, int sum_val) {
        if (!node->left && !node->right) {
            if (0 == sum_val) _result.push_back(_path);
            return;
        }
        if (node->left) {
            _path.push_back(node->left->val);
            getPath(node->left, sum_val - node->left->val);
            _path.pop_back();
        }

        if(node->right){
            _path.push_back(node->right->val);
            getPath(node->right, sum_val- node->right->val);
        }
    }

public:
    vector<vector<int>> pathSum_3(TreeNode *root, int targetSum) {
        _result.clear();
        _path.clear();
        if (!root) return _result;

        _path.push_back(root->val);
        getPath(root, targetSum - root->val);
        return _result;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    auto t9 = new TreeNode(9);
    auto t15 = new TreeNode(15);
    auto t7 = new TreeNode(15);
    auto t20 = new TreeNode(20, t15, t7);
    auto t3 = new TreeNode(3, t9, t20);

    mat_t rel = {
            {3},
            {9,  20},
            {15, 15}
    };
    IC(rel);
    IC(solution->levelOrder(t3) == rel);

    int targetSum = 38;
    IC(solution->pathSum(t3, targetSum));
    IC();
    IC(solution->pathSum_2(t3, targetSum));

    IC();
    IC(solution->pathSum_3(t3, targetSum));


    delete t9;
    delete t15;
    delete t7;
    delete t20;
    delete t3;
    // code end

    delete solution;
    return 0;
}


