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
  int k = 3;
  char fill = 'x';

  vector<string> res;
  int i = 0;
  string item;
  for(const char &c: s){
    item.push_back(c);

    if(item.size() == k) {
      res.emplace_back(item);
      item.clear();
    }
  }


  if(item.size() > 0){
    for(int i = item.size(); i< k; i++)
      item.push_back(fill);

    res.emplace_back(item);
  }



  out_vec(res,"res");
  return 0;
}
