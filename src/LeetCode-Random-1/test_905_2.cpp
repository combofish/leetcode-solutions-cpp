/**
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include "combofish_utils.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char **argv) {
  vector<int> nums = {3,1,2,4};

  int n = nums.size();
  int i = 0;
  int j = n - 1;
  vector<int> res(n,0);

  for(const int &n : nums){
    if(n%2 == 0){
      res[i++] = n;
    }else{
      res[j--] = n;
    }
  }

  out_vec(res, "res");
  return 0;
}
