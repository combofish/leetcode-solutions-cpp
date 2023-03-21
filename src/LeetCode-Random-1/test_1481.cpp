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
  vector<int> arr = {1};

  unordered_map<int, int> umap;
  for(const int &i: arr)
    ++umap[i];

  for(auto &u:umap){
    cout<< u.first << " , "<<u.second<<endl;
  }

  vector<int> rec;
  for(auto &u:umap)
    rec.emplace_back(u.second);

  sort(rec.begin(), rec.end());
  for(const int &i : rec)
    outln(i, "---i");

  int k = 1;
  int i = 0;
  while(k>0){
    if(k < rec[i]){
      break;
    }else{
      // k >= rec[i];
      k -= rec[i++];
    }

    out(i, " i ");
    outln(k, "left k: ");
  }

  int res = rec.size() - i;
  outln(res, "res");
  return 0;
}
