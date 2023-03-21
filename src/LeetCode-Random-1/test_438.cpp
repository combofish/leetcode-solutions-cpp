/*
 * @Author: your name
 * @Date: 2022-04-27 21:23:11
 * @LastEditTime: 2022-04-28 08:52:13
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /use_for_test/test_417 copy.cpp
 */

/**
 *
 */

#include "combofish_utils.hpp"

int main(int argc, char **argv) {

  vector<int> res;
  //"aaaaaaaaaa"
  //"aaaaaaaaaaaaa"
  string s = "aaaaaaaaaa", p = "aaaaaaaaaaaaa";
  int n = s.size();
  int k = p.size();

  unordered_map<char, int> umap_rec;
  for (const char &c : p)
    ++umap_rec[c];

  bool hasAng = false;
  for (int i = 0; i < n - k + 1; ++i) {
    // outln(i,"i");

    unordered_map<char, int> umap;
    for (int j = 0; j < k; j++)
      ++umap[s[i + j]];

    cout << "umap: ";
    for (auto &u : umap)
      cout << "(" << u.first << "," << u.second << ")";
    cout << endl;

    cout << "umap_rec: ";
    for (auto &u : umap_rec)
      cout << "(" << u.first << "," << u.second << ")";
    cout << endl;

    bool same = true;
    for (auto &u : umap)
      if (u.second != umap_rec[u.first]) {
        same = false;
        break;
      }

    outln(same, "same");
    if (same) {
      hasAng = true;
      res.emplace_back(i);
      break;
    }
  }

  if (hasAng) {
    unordered_map<char, int> umap_cmp;
    for (int j = res.back() + 1; j + k <= s.size(); ++j) {
      out(j, "\nj>>>");
      out(s[j], "s[j]");
      out(s[j + k - 1], "s[j+k]");

      ++umap_cmp[s[j + k - 1]];
      --umap_cmp[s[j - 1]];

      bool same = true;
      for (auto &u : umap_cmp) {
        out(u.first, "(");
        cout << ",";
        out(u.second, " ");
        cout << ")";

        if (u.second != 0) {
          same = false;
          break;
        }
      }

      if (same) {
        res.emplace_back(j);
      }
    }
  }

  out_vec(res, "res");
  return 0;
}
