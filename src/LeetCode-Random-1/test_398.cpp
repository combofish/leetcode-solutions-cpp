/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>

int main(int argc, char **argv) {
  vector<int> nums = {1, 2, 3, 3, 3};
  int target = 3;

  srand(int(time(nullptr)));
  vector<int> rec;

  for (int i = 0; i < nums.size(); i++)
    if (nums[i] == target)
      rec.emplace_back(i);

  int n = -1;
  int rec_size = rec.size();
  if (rec_size == 1)
    n = rec[0];

  n = rec[rand() % rec_size];
  for (int j = 0; j < 20; j++){
    int inn = rand()%3;
    outln(inn, "j");
  }

  out_vec(rec);
  outln(n, "res");

  return 0;
}
