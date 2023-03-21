/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <string>

int main(int argc, char **argv) {
  vector<int> nums = {0, 2, 4, 7};
  vector<string> res;

  int start_n = nums[0];
  int prev_n = nums[0];
  string item;

  for (int i = 1; i < nums.size(); i++) {
    int cur_n = nums[i];
    out(start_n, "start_n");
    out(prev_n, "prev_n");
    outln(cur_n, "cur_n");

    if (cur_n == prev_n + 1) {
      prev_n = cur_n;
      continue;
    }

    if (cur_n > prev_n + 1) {

      if (prev_n == start_n) {
        item = std::to_string(prev_n);
      } else {
        item = std::to_string(start_n) + "->" + std::to_string(prev_n);
      }

      start_n = cur_n;
    }

    prev_n = cur_n;
    res.emplace_back(item);
  }

  if (prev_n == start_n) {
    item = std::to_string(prev_n);
  } else {
    item = std::to_string(start_n) + "->" + std::to_string(prev_n);
  }

  res.emplace_back(item);

  out_vec(res);
  //  outln(n, "res");

  return 0;
}
