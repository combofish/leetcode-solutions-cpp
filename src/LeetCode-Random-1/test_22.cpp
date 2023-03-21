/**
 *
 */

#include "combofish_utils.hpp"
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

void backtrack(vector<string> &res, string &item, int open, int close, int n) {
  if (item.size() == n * 2) {
    res.emplace_back(item);
    return;
  }
  if (open < n) {
    item.push_back('(');
    backtrack(res, item, open + 1, close, n);
    item.pop_back();
  }
  if (close < open) {
    item.push_back(')');
    backtrack(res, item, open, close + 1, n);
    item.pop_back();
  }
}

int main(int argc, char **argv) {

  int n = 3;

  vector<string> res;
  string item;
  backtrack(res, item, 0, 0, n);

  out_vec(res);

  return 0;
}
