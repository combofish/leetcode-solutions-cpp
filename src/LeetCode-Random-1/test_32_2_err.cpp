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
  string s = "()(()";
  int res = 0;

  int right_cont = 0, left_conut = 0;

  for(const char &c: s){
    if(c == '('){
      ++right_cont;
    }else{
      if(right_cont >= left_conut + 1){
        ++left_conut;
      }else{
        // not parent

        right_cont = 0;
        left_conut = 0;
      }
    }

    if(right_cont == left_conut)
      res = std::max(res, left_conut * 2);

    out(right_cont, "right_cont");
    out(left_conut, "left_count");
    outln(res, "res");
  }



  outln(res, "res");
  return 0;
}
