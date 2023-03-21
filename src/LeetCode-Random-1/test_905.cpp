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

  vector<int> res;
  for(const int &n: nums)
    if(n%2 == 0)
      res.emplace_back(n);

  for(const int &n: nums)
    if(n%2 == 1)
      res.emplace_back(n);

  out_vec(res, "res");
  return 0;
}
