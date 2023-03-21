/**
-- method: 后序遍历

--result:
执行用时：40 ms, 在所有 C++ 提交中击败了29.26%的用户
内存消耗：27.8 MB, 在所有 C++ 提交中击败了52.12%的用户
通过测试用例：62 / 62
 */

#include "combofish_utils.hpp"
#include <climits>
#include <cstddef>
#include <string>

class Solution {
public:
  // function start.

  // function end.
};

class Codec {
  void postOrder(TreeNode *root, vector<int> &arr) {
    if (root == nullptr)
      return;

    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.emplace_back(root->val);
  }

  vector<string> split(const string &str, char dec) {
    int pos = 0, start = 0;
    vector<string> res;
    while (pos < str.size()) {
      while (pos < str.size() && str[pos] == dec) {
        pos++;
      }
      start = pos;
      while (pos < str.size() && str[pos] != dec) {
        pos++;
      }
      if (start < str.size()) {
        res.emplace_back(str.substr(start, pos - start));
      }
    }
    return res;
  }

  TreeNode *construct(int lower, int upper, stack<int> &st) {
    if (st.size() == 0 || st.top() < lower || st.top() > upper)
      return nullptr;

    int val = st.top();
    st.pop();

    TreeNode *root = new TreeNode(val);
    root->right = construct(val, upper, st);
    root->left = construct(lower, val, st);
    return root;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string s = "";
    vector<int> arr;

    postOrder(root, arr);
    if (arr.size() == 0)
      return s;
    for (int i = 0; i < arr.size() - 1; ++i)
      s.append(std::to_string(arr[i]) + ',');

    s.append(std::to_string(arr.back()));
    return s;
  }
  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.size() == 0)
      return nullptr;

    vector<string> arr = split(data, ',');
    stack<int> st;
    for (auto &str : arr) {
      st.emplace(stoi(str));
    }

    return construct(INT_MIN, INT_MAX, st);
  }
};

int main() {

  Solution *solution = new Solution();

  TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

  // code start
  Codec *ser = new Codec();
  Codec *deser = new Codec();
  string tree = ser->serialize(root);
  TreeNode *ans = deser->deserialize(tree);

  IC(tree);

  IC(ser->serialize(ans) == tree);

  return 0;
}
