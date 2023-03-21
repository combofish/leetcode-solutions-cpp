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

bool isCanUse(const string &s, int right, int len){
  int res = 0;
  for(int i = right; i<len; ++i){
    if (s[i] == '(') res++;
    else res--;

    if(res < 0) return false;
  }

  if(res == 0) return true;
  else return false;
}

int findMaxlength(const string &s, int idx){
  cout<< "Call findMaxlength with idx: "<< idx<<endl;
  int res = -1;
  vector<int> rec;

  int tmp = 0;
  for(int i = idx; i< s.size(); i++){
    if(s[i] == '(') ++tmp;
    else --tmp;

    if(tmp == 0) rec.emplace_back(i - idx + 1);
    if(tmp < 0) {
      res = -1;
      break;
    }
  }

  if(rec.size() == 0) res = -1;
  else res = rec.back();
  return res;
}

int main(int argc, char **argv) {
  string s = ")()())";

  int res = 0 ;
  for(int i = 0; i< s.size(); i++){
    int max_length = findMaxlength(s, i);

    if(max_length == -1) continue;

    res = std::max(res, max_length);
    outln(max_length, "max_length");

  }

  outln(res, "res");
  return 0;
}
