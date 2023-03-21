/**
 * OVer time
 */
#include "combofish_utils.hpp"
#include <algorithm>


int main(int argc, char **argv) {
  vec_t nums = {1,2,3};

  int i = nums.size() - 2;

  while(i>=0 && nums[i]>= nums[i+1])
    --i;

  if(i>=0){
    int j = nums.size() -1;
    while(j >= 0 && nums[i] >= nums[j])
      --j;

    std::swap(nums[i],nums[j]);
  }
  
  std::reverse(nums.begin() + i + 1, nums.end());
  return 0;
}
