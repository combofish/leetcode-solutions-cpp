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


    // 1 umap, sort, 适用普通二叉树
private:
    void traversal(TreeNode *node, unordered_map<int, int> &umap) {
        if (!node) return;
        traversal(node->left, umap);
        umap[node->val]++;
        traversal(node->right, umap);
    }

    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    }

public:
    vector<int> findMode(TreeNode *root) {
        vector<int> results;
        if (!root) return results;
        unordered_map<int, int> umap;
        traversal(root, umap);

        vector<pair<int, int>> vec(umap.begin(), umap.end());
        sort(vec.begin(), vec.end(), cmp);


        results.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) results.push_back(vec[i].first);
        }
        return results;

    }

    // 2 iterate
    vector<int> findMode_2(TreeNode *root) {
        vector<int> results;
        if (!root) return results;

        stack<TreeNode *> sta;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        int maxCount = 0;
        int count = 0;
        while (cur || !sta.empty()) {
            if (cur) {
                sta.push(cur);
                cur = cur->left;
            } else {
                cur = sta.top();
                sta.pop();

//                IC(cur->val);

                if (!pre) {
                    count = 1;
                } else if (pre->val == cur->val) {
                    count++;
                } else {
                    count = 1;
                }

                if (count == maxCount) results.push_back(cur->val);

                if (count > maxCount) {
                    maxCount = count;
                    results.clear();
                    results.push_back(cur->val);
                }

                pre = cur;
                cur = cur->right;
            }
        }
        return results;
    }


    // 3
private:
    vector<int> _result;
    int _count = 0;
    int _maxCount = 0;
    TreeNode *_pPre = nullptr;

    void traversal_3(TreeNode *node) {
        if (!node) return;
        traversal_3(node->left);

        if (!_pPre) _count = 1;
        else if (_pPre->val == node->val)
            _count++;
        else _count = 1;
        if (_count == _maxCount) _result.push_back(node->val);
        if (_count > _maxCount) {
            _result.clear();
            _maxCount = _count;
            _result.push_back(node->val);
        }

        _pPre = node;
        traversal_3(node->right);

    }

public:
    vector<int> findMode_3(TreeNode *root) {
        _result.clear();
        if (!root) return _result;
        traversal_3(root);
        return _result;
    }

    // function end.
};


int main() {

    auto solution = new Solution();

    // code start
    auto t9 = new TreeNode(13);
    auto t15 = new TreeNode(20);
    auto t27 = new TreeNode(27);
    auto t20 = new TreeNode(20, t15, t27);
    auto t13 = new TreeNode(13, t9, t20);
    auto node = t13;


    IC(solution->levelOrder(node));

    vector<int> rel = {13, 20};
    IC(rel);
    IC(solution->findMode(node));
    IC(solution->findMode_2(node));
    IC(solution->findMode_3(node));


    deleteTreeNode(node);



    // code end

    delete solution;
    return 0;
}




