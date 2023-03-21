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
  int x = 1, y = 4;
  int res = 0;

  while(x>0 || y>0){
    int a1 = x%2;
    int a2 = y%2;

    if(a1 != a2) ++res;
    x/=2;
    y/=2;

    out(a1,"a1");
    out(a2,"a2");
    out(x,"x");
    out(y,"y");
    outln(res,"res");
  }

  outln(res, "res");
  return 0;
}
