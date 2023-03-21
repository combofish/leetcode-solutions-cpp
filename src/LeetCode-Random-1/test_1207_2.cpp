/**
-- method: umap, uset, insert, cmp_size

--result:
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了63.09%的用户
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
    for (auto &u : umap)
      uset.insert(u.second);

    return uset.size() == umap.size();
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
