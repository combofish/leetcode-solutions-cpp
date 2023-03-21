/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>

// bool check_equ(vector<int> &vec) {
//   int a = vec.front();
//   for (auto &v : vec)
//     if (v != a)
//       return false;

//   return true;
// }

int main(int argc, char **argv) {
  vector<int> nums = {1, 1000000000};
  int res = 0;

  auto check_equ = [](const vector<int> &vec) {
    int a = vec.front();
    for (auto &v : vec)
      if (v != a)
        return false;

    return true;
  };

  while (!check_equ(nums)) {
    std::sort(nums.begin(), nums.end());
    std::for_each(nums.begin(), nums.end(), [](int &i) { ++i; });
    --nums.back();
    ++res;
  }

  out_vec(nums, "Nums");

  out(res);

  return 0;
}
