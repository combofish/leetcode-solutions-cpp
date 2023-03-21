/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <functional>
#include <type_traits>

int main(int argc, char **argv) {
  string s = "csd";
  int result;
  unordered_map<char,int> umap;
  for(const char &c:s){
    ++umap[c];
  }

  

  outln(result, "result");

  outln(s, "s");

  return 0;
}
