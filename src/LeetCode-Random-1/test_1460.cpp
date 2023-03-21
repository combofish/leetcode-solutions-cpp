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
  bool res = true;
  vector<int> target = {1,2,3,4};
  vector<int> arr = {2,3,1,3};

  unordered_map<int, int> umap;
  for(const int &n: target)
    ++umap[n];

  for(auto u: umap)
    cout<< u.first<< ","<< u.second<<") ";
  cout<<endl;

  for(const int &n: arr)
    --umap[n];

  for(auto u: umap)
    cout<< u.first<< ","<< u.second<<") ";
  cout<<endl;

  for(auto &u:umap){
    if(u.second != 0){
      res = false;
    }
  }

  outln(res, "res");
  return 0;
}
