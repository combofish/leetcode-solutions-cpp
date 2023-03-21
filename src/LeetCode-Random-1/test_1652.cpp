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
  vector<int> code = {2, 4, 9, 3};

  int k = -2;
  int n = code.size();

  vector<int> res(n, 0);
  if (k == 0) {
    // return res;
  }

  for (int i = 0; i < n; i++) {
    int inner = 0;

    for (int j = 1; j <= std::max(k, -k); j++) {
      if (k > 0) {
        res[i] += code[(i + j) % n];
      } else {
        res[i] += code[(i - j + n) % n];
      }
    }
  }

  for (auto &s : res)
    cout << "RES: " << s << endl;

  return 0;
}
