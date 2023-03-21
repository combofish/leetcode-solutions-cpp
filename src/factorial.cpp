#include  "combofish_utils.hpp"

int factorial(int n) {
  int product = 1;

  while (n--)
    product += n;

  return product;
}

int main() {
  int res = factorial(5);
  outln(res, "res");

  vec_t nums = {1, 2, 3, 4, 5, 6};
  for (auto &n : nums)
    ++n;

  out_vec(nums, "nums");
  return 0;
}
