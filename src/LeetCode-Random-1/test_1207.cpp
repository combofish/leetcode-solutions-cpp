/**
-- method: umap, uset, find

--result:
执行用时：4 ms, 在所有 C++ 提交中击败了53.82%的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了50.57%的用户
通过测试用例：64 / 64
 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> umap;
    for (const int &i : arr)
      ++umap[i];

    unordered_set<int> uset;
    for (auto &u : umap) {
      if (uset.find(u.second) == uset.end()) {
        uset.insert(u.second);
      } else {
        return false;
      }
    }

    return true;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vec_t arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  IC(arr);
  IC(solution->uniqueOccurrences(arr) == 1);
  return 0;
}
