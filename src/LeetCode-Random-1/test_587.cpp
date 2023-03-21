/**
 *
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// Andrew
int cross(vector<int> &p, vector<int> &q, vector<int> &r) {
  return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
}

int main(int argc, char **argv) {

  vector<vector<int>> trees, res;
  trees = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
  /**
  int n = trees.size();
  if (n < 4) {
  }

  std::sort(trees.begin(), trees.end(),
            [](const vector<int> &a, const vector<int> &b) {
              if (a[0] == b[0])
                return a[1] < b[1];
              return a[0] < b[0];
            });

  vector<int> hull;
  vector<bool> used(n, false);
  hull.emplace_back(0);

  for (int i = 1; i < n; i++) {
    while (hull.size() > 1 && cross(trees[hull[hull.size() - 2]],
                                    trees[hull.back()], trees[i]) < 0) {
      used[hull.back()] = false;
      hull.pop_back();
    }
    used[i] = true;
    hull.emplace_back(i);
  }

  int m = hull.size();
  cout << "Half m :" << m << endl;

  for (int i = n - 2; i >= 0; i--) {
    if (!used[i]) {
      while (hull.size() > m && cross(trees[hull[hull.size() - 2]],
                                      trees[hull.back()], trees[i]) < 0) {
        used[hull.back()] = false;
        hull.pop_back();
      }
      used[i] = true;
      hull.emplace_back(i);
    }
  }

  hull.pop_back();
  for (auto &v : hull)
    res.emplace_back(trees[v]);

  */

  int n = trees.size();
  //  if (n < 4)
  //   return trees;

  sort(trees.begin(), trees.end(),
       [](const vector<int> &a, const vector<int> &b) {
         if (a[0] == b[0])
           return a[1] < b[1];
         return a[0] < b[0];
       });

  vector<int> hull;
  vector<bool> used(n, false);
  hull.emplace_back(0);
  for (int i = 1; i < n; i++) {
    while (hull.size() > 1 && cross(trees[hull[hull.size() - 2]],
                                    trees[hull.back()], trees[i]) < 0) {
      used[hull.back()] = false;
      hull.pop_back();
    }
    used[i] = true;
    hull.emplace_back(i);
  }
  // for (int i = 1; i < n; i++) {
  //   if (hull.size() > 1 &&
  //       cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) <
  //       0) {
  //     used[hull.back()] = false;
  //     hull.pop_back();
  //   }
  //   used[i] = true;
  //   hull.emplace_back(i);
  // }

  int m = hull.size();
  cout << "half m: " << m << endl;

  for (int i = n - 2; i >= 0; i--) {
    if (!used[i]) {
      while (hull.size() > m && cross(trees[hull[hull.size() - 2]],
                                      trees[hull.back()], trees[i]) < 0) {
        used[hull.back()] = false;
        hull.pop_back();
      }
      used[i] = true;
      hull.emplace_back(i);
    }
  }
  hull.pop_back();
  //  vector<vector<int>> res;
  for (auto &c : hull)
    res.emplace_back(trees[c]);

  for (auto &s : trees)
    cout << "(" << s[0] << ", " << s[1] << ") ";
  cout << endl;

  cout << "Res: " << endl;
  for (auto &s : res)
    cout << "(" << s[0] << ", " << s[1] << ") ";
  cout << endl;

  return 0;
}
