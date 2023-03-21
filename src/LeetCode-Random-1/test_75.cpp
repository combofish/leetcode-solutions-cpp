#include "combofish_utils.hpp"

void trans(vec_t &nums){
  int i = 0;
  int n = nums.size();

  while(i<n-1){
    int cur_n = nums[i];
    auto next_min_p = std::min_element(nums.begin() + i + 1, nums.end());
    if(*next_min_p < cur_n){
      std::swap(nums[i], *next_min_p);
    }
    ++i;
  }
  
}

int main(){
  vec_t nums = {2,0,2,1,1,0};
  trans(nums);
  out_vec(nums);
  return 0;
}
