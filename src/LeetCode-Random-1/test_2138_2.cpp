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
  string s = "adcdefghij";
  int k = 14;
  char fill = 'x';

  vector<string> res;
  int i = 0;
  int n = s.size();

  while(i<n){
    res.emplace_back(s.substr(i, k));
    i+=k;
  }

  res.back() += string(k - res.back().size(), fill);
  out_vec(res,"res");
  return 0;
}
