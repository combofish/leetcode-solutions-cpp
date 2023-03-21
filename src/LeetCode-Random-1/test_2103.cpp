/**
 *
 */

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

int main(int argc, char **argv) {
  string rings = "B0B6G0R6R0R6G9";
  int res = 0;
  unordered_map<char, unordered_set<char>> rec;
  int n = rings.size();

  for (int i = 0; i < n / 2; i++) {
    rec[rings[i * 2 + 1]].insert(rings[i * 2]);
  }

  for (auto &r : rec) {
    if (r.second.size() == 3)
      ++res;
  }

  cout << "Res: " << res << endl;

  return 0;
}
