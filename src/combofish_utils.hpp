/*
 * @Author: combofish
 * @Date: 2022-04-23 19:22:57
 * @LastEditTime: 2022-04-27 18:55:56
 * @LastEditors: your name
 * @Description: utils
 * @FilePath: /use_for_test/combofish_utils.hpp
 */

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <ctime>
#include <functional>
#include <icecream.hpp>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// use fmt lib.

// #include <fmt/printf.h>
// #include <fmt/format-inl.h>
// #include <fmt/std.h>
#include <fmt/core.h>
#include <fmt/format.h>


#ifndef LEETCODE_SOLUTION_CPP_COMBOFISH_UTILS_H
#define LEETCODE_SOLUTION_CPP_COMBOFISH_UTILS_H


using std::cout;
using std::endl;

using std::string;

using std::array;
using std::vector;

using std::list;
using std::queue;
using std::stack;

using std::unordered_map;
using std::unordered_set;

using std::stringstream;

using std::pair;
using std::tuple;

using std::make_shared;
using std::max;
using std::sort;
using std::swap;

typedef vector<vector<vector<int>>> tensor_t;
typedef vector<vector<int>> mat_t;
typedef vector<int> vec_t;

/**************************************************************************
 *
 * define start
 *
 *************************************************************************/

class person {
public:
    void out();
};

struct ListNode;
struct TreeNode;

namespace treenode_tools {
    // int a = 1;

    // 二叉树的层序遍历
    std::vector<std::vector<int>> levelOrder(TreeNode *root);

    // Recursive delete TreeNode.
    void deleteTreeNode(TreeNode *pNode);

    // 二叉树的最大深度
    int maxDepth(TreeNode *root);

    // 从字符串生成二叉树 "[1,null,2,null,null,]" -> TreeNode
    TreeNode *string2TreeNode(const std::string &str);

    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root);

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data);

    // 从前序遍历的数据生成二叉树
    TreeNode *traversalDeserialize(std::list<std::string> &dataList);
}// namespace treenode_tools

// 从列表构建链表
ListNode *vecT2ListNode(const vector<int> &nums);

// 输出链表
void outListNode(ListNode *node, string s = "ListNode");

// 输出栈数据
template<typename T>
void outStack(const stack<T> &cst);

// 删除 ListNode
void deleteListNode(ListNode *node);


/**************************************************************************
 *
 * define end
 *
 *************************************************************************/


void person::out() {
    IC("HH");
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};


template<typename T>
void outStack(const stack<T> &cst) {
    vector<T> vec;
    stack<T> st = cst;

    while (!st.empty()) {
        vec.emplace_back(st.top());
        st.pop();
    }

    std::reverse(vec.begin(), vec.end());
    IC(vec);
}

void out_qu(queue<int> qu_) {
    vec_t qu;
    while (!qu_.empty()) {
        qu.emplace_back(qu_.front());
        qu_.pop();
    }

    IC(qu);
}


ListNode *vecT2ListNode(const vector<int> &nums) {
    if (nums.empty())
        return nullptr;

    ListNode *head = new ListNode(nums.front());
    ListNode *cur = head;

    for (int i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }

    return head;
}

void deleteListNode(ListNode *node) {
    while (node != nullptr) {
        ListNode *tmp = node;
        node = node->next;
        delete tmp;
    }
}


void deleteListNode(ListNode *input, int n) {
    ListNode *cur = input;
    while (n-- && cur != nullptr) {
        ListNode *tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}


void outListNode(ListNode *node, string s) {
    vec_t res;
    while (node != nullptr) {
        res.emplace_back(node->val);
        node = node->next;
    }

    //    delete node;
    IC(s, res);
}

template<typename T>
void out_mat(vector<vector<T>> &mat, string s = "Res") {

    cout << s << endl;
    for (auto line: mat) {
        for (auto n: line) {
            cout << "   " << n;
        }
        cout << endl;
    }

    cout << endl;
}

template<typename T>
void out_vec(vector<T> &vec, string s = "Res") {
    cout << s << " :";
    for (auto &c: vec)
        cout << c << ", ";
    cout << endl;
}

// template <typename T> void out(T &t) { cout << t << endl; }
// template <typename T> void outln(T &t) { cout << t; }

template<typename T>
void out(T t, string s = "Res") {
    cout << s << ": " << t << " ";
}

template<typename T>
void outln(T t, string s = "Res") {
    cout << s << ": " << t << endl;
}

void out_line() { cout << endl; }

void posterOrder(TreeNode *root) {
    if (root != nullptr) {
        cout << root->val << endl;
        posterOrder(root->left);
        posterOrder(root->right);
    }
}

void middleOrder(TreeNode *root) {
    if (root != nullptr) {
        middleOrder(root->left);
        cout << root->val << endl;
        middleOrder(root->right);
    }
}

void hindOrder(TreeNode *root) {
    if (root != nullptr) {
        hindOrder(root->left);
        hindOrder(root->right);
        cout << root->val << endl;
    }
}

namespace treenode_tools {
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        std::queue<TreeNode *> qu;
        qu.push(root);

        int depth = 0;
        while (!qu.empty()) {
            int n = qu.size();
            depth++;
            while (n--) {
                auto node = qu.front();
                qu.pop();
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
        }

        return depth;
    }

    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;

        std::queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            int n = qu.size();
            std::vector<int> vec;
            while (n--) {
                TreeNode *node = qu.front();
                qu.pop();
                vec.emplace_back(node->val);

                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            result.emplace_back(vec);
        }

        return result;
    }

    void deleteTreeNode(TreeNode *pNode) {
        if (!pNode) return;
        deleteTreeNode(pNode->left);
        deleteTreeNode(pNode->right);
        delete pNode;
    }

    TreeNode *string2TreeNode(const std::string &str) {
        if (str.front() == '[' && str.back() == ']')
            return deserialize(str.substr(1, str.size() - 2));
        else
            return deserialize(str);
    }

    std::string serialize(TreeNode *root) {
        if (!root) return "null,";

        std::string result;
        std::stack<TreeNode *> st;
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

        //        IC(dataList);
        return traversalDeserialize(dataList);
    }


    TreeNode *traversalDeserialize(std::list<std::string> &dataList) {
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

}// namespace treenode_tools


#endif //LEETCODE_SOLUTION_CPP_COMBOFISH_UTILS_H

