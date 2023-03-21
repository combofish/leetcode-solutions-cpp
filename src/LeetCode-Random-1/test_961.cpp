/**
-- method: umap, for

--result:
执行用时：52 ms, 在所有 C++ 提交中击败了16.85%的用户
内存消耗：29.4 MB, 在所有 C++ 提交中击败了25.66%的用户
通过测试用例：102 / 102

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.
  int repeatedNTimes(vector<int> &nums) {
    int n = nums.size() / 2;
    IC(nums.size());

    unordered_map<int, int> umap;
    for (auto &i : nums)
      ++umap[i];

    IC(umap, n);

    for (auto &u : umap)
      if (u.second == n)
        return u.first;

    return -1;
  }
  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start
  vec_t nums = {5, 1, 5, 2, 5, 3, 5, 4};
  IC(nums);
  IC(solution->repeatedNTimes(nums));
  IC(5);
  return 0;
}
