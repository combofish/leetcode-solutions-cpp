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
  string s = "RLRRLLRLRL";

  int right_count = 0, left_count = 0;
  int res = 0;

  for(const char &c: s){
    if(c == 'R') {
      ++right_count;
    }else{
      ++left_count;
    }

    if(right_count == left_count){
      ++res;
      right_count = left_count = 0;
    }
  }


  outln(res, "res");
  return 0;
}
