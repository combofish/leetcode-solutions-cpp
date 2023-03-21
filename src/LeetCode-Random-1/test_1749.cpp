/**
 *
 */

#include "combofish_utils.hpp"

int main(int argc, char **argv) {
  vector<int> nums = {1, -3, 2, 3, -4};

  int res = 0;
  int max_n = 0, min_n = 0;

  // for (const int &n : nums) {
  //   max_n = std::max(n, max_n + n);
  //   min_n = std::min(n, min_n + n);
  //   res = std::max(res, std::max(std::abs(max_n), std::abs(min_n)));
  // }

  for (const int &n : nums) {
    min_n = std::min(n, min_n + n);
    max_n = std::max(n, max_n + n);
    res = std::max(res, std::max(abs(min_n), abs(max_n)));
  }
  out(res);

  return 0;
}
