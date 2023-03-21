/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>

int main(int argc, char **argv) {
  vector<int> arr = {2, 2, 3, 4};

  unordered_map<int, int> umap;
  for (const int &i : arr) {
    ++umap[i];
  }

  for (auto &u : umap) {

    cout << u.first << " " << u.second << endl;
  }

  unordered_set<int> uset;
  for (auto &u : umap)
    if (u.first == u.second)
      uset.insert(u.first);

  int n = uset.size();

  for (auto &u : uset) {
    cout << u << endl;
  }
  outln(n, "res");

  return 0;
}
