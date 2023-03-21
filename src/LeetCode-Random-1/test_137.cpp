/**
 *
 */

#include "combofish_utils.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char **argv) {
  vector<int> arr = {2, 2, 3, 2};

  unordered_map<int, int> umap, umap_idx;
  int i = 0;
  for (const int &n : arr) {
    ++umap[n];
    umap_idx[n] = i++;
  }

  int res = 0;
  for (auto &p : umap)
    if (p.second == 1)
      res = p.first;

  outln(res, "res");
  return 0;
}
