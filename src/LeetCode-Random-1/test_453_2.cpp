/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>

int main(int argc, char **argv) {
  vector<int> nums = {1, 1000000000};
  int res = 0;

  int min_n = *std::min_element(nums.begin(), nums.end());
  for (const int &i : nums)
    res += i - min_n;

  out_vec(nums, "Nums");

  out(res);

  return 0;
}
