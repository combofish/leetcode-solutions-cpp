/**
-- method: list_2vec, while

--result:
执行用时：228 ms, 在所有 C++ 提交中击败了15.20%的用户
内存消耗：125.1 MB, 在所有 C++ 提交中击败了29.00%的用户
通过测试用例：85 / 85
 */

#include "combofish_utils.hpp"

class Solution {
  void listNode2Vec(ListNode *node, vector<int> &arr) {
    ListNode *root = node;

    while (root != nullptr) {
      arr.emplace_back(root->val);
      root = root->next;
    }
  }

public:
  // function start.
  bool isPalindrome(ListNode *head) {
    vector<int> arr;
    listNode2Vec(head, arr);

    int n = arr.size();
    int i = 0;

    while (i < n - i - 1) {
      if (arr[i] != arr[n - i - 1])
        return false;

      i++;
    }

    return true;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  ListNode *node = new ListNode(
      1, new ListNode(
             2, new ListNode(
                    3, new ListNode(3, new ListNode(2, new ListNode(1))))));

  out_list_node(node);

  IC(solution->isPalindrome(node));

  return 0;
}
