/**
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

int main(int argc, char **argv) {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};

  unordered_map<int, int> umap1, umap2;

  for (const int &i : nums1)
    ++umap1[i];

  for (const int &i : nums2)
    ++umap2[i];

  vector<int> res;
  for (auto &r : umap1) {
    if (umap2.find(r.first) != umap2.end()) {
      int n = std::min(r.second, umap2[r.first]);

      for (int i = 0; i < n; i++)
        res.push_back(r.first);
    }
  }

  for (auto &i : res)
    cout << i << endl;

  return 0;
}
