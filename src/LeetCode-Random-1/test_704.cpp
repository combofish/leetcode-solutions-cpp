/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <string>

int main(int argc, char **argv) {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 10;
  int res = -1;

  int start_n = 0, end_n = nums.size()-1;

  int n = 0;
  while(start_n <= end_n){
    int cur_n = start_n +  (end_n - start_n) /2;
    out(cur_n, "cur_n");
    if(nums[cur_n] == target) {
      res = cur_n;
      break;
    }else if(nums[cur_n] < target){
      start_n = cur_n + 1 ;
    }else{
      end_n = cur_n -1;
    }

    
    out(start_n, "start_n");
    outln(end_n, "end_n");


    ++n;
    if(n == 5)
      break;
  }

  //  out_vec(res);
  outln(res, "res");

  return 0;
}
